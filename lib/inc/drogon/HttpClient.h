/**
 *
 *  HttpClient.h
 *
 *  An Tao
 *
 *  Copyright 2018, An Tao.  All rights reserved.
 *  https://github.com/an-tao/drogon
 *  Use of this source code is governed by the MIT license
 *  that can be found in the License file.
 *
 *  Drogon
 *
 */
#pragma once

#include <drogon/HttpTypes.h>
#include <drogon/drogon_callbacks.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpRequest.h>
#include <trantor/utils/NonCopyable.h>
#include <trantor/net/EventLoop.h>
#include <functional>
#include <memory>
namespace drogon
{
class HttpClient;
typedef std::shared_ptr<HttpClient> HttpClientPtr;

/// Asynchronous http client
/**
 * HttpClient implementation object uses the HttpAppFramework's event loop by
 * default, so you should call app().run() to make the client work.
 * Each HttpClient object establishes a persistent connection with the server.
 * If the connection is broken, the client attempts to reconnect
 * when calling the sendRequest method.
 *
 * Using the static mathod newHttpClient(...) to get shared_ptr of the object
 * implementing the class, the shared_ptr is retained in the framework until all
 * response callbacks are invoked without fear of accidental deconstruction.
 *
 * TODO:SSL server verification
 */
class HttpClient : public trantor::NonCopyable
{
  public:
    /**
     * @brief Send a request asynchronously to the server
     *
     * @param req The request sent to the server.
     * @param callback The callback is called when the response is received from
     * the server.
     * @note
     * The request object is altered(some headers are added to it) before it is
     * sent, so calling this method with a same request object in different
     * thread is dangerous.
     */
    virtual void sendRequest(const HttpRequestPtr &req,
                             const HttpReqCallback &callback) = 0;

    /**
     * @brief Send a request asynchronously to the server
     *
     * @param req The request sent to the server.
     * @param callback The callback is called when the response is received from
     * the server.
     * @note
     * The request object is altered(some headers are added to it) before it is
     * sent, so calling this method with a same request object in different
     * thread is dangerous.
     */
    virtual void sendRequest(const HttpRequestPtr &req,
                             HttpReqCallback &&callback) = 0;

    /// Set the pipelining depth, which is the number of requests that are not
    /// responding.
    /**
     * If this method is not called, the default depth value is 0 which means
     * the pipelining is disabled. For details about pipelining, see
     * rfc2616-8.1.2.2
     */
    virtual void setPipeliningDepth(size_t depth) = 0;

    /// Enable cookies for the client
    /**
     * @param flag if the parameter is true, all requests sent by the client
     * carry the cookies set by the server side. Cookies are disabled by
     * default.
     */
    virtual void enableCookies(bool flag = true) = 0;

    /// Add a cookie to the client
    /**
     * @note
     * These methods are independent of the enableCookies() method. Whether the
     * enableCookies() is called with true or false, the cookies added by these
     * methods will be sent to the server.
     */
    virtual void addCookie(const std::string &key,
                           const std::string &value) = 0;

    /// Add a cookie to the client
    /**
     * @note
     * These methods are independent of the enableCookies() method. Whether the
     * enableCookies() is called with true or false, the cookies added by these
     * methods will be sent to the server.
     */
    virtual void addCookie(const Cookie &cookie) = 0;

    /**
     * @brief Creaet a new HTTP client which use ip and port to connect to
     * server
     *
     * @param ip The ip address of the HTTP server
     * @param port The port of the HTTP server
     * @param useSSL if the parameter is set to true, the client connects to the
     * server using https.
     * @param loop If the loop parameter is set to nullptr, the client uses the
     * HttpAppFramework's event loop, otherwise it runs in the loop identified
     * by the parameter.
     * @return HttpClientPtr The smart pointer to the new client object.
     * @note: The ip parameter support for both ipv4 and ipv6 address
     */
    static HttpClientPtr newHttpClient(const std::string &ip,
                                       uint16_t port,
                                       bool useSSL = false,
                                       trantor::EventLoop *loop = nullptr);

    /// Get the event loop of the client;
    virtual trantor::EventLoop *getLoop() = 0;

    /// Get the number of bytes sent or received
    virtual size_t bytesSent() const = 0;
    virtual size_t bytesReceived() const = 0;

    /// Create a Http client using the hostString to connect to server
    /**
     *
     * @param hostString this parameter must be prefixed by 'http://' or
     * 'https://'.
     *
     * Examples for hostString:
     * @code
       https://www.baidu.com
       http://www.baidu.com
       https://127.0.0.1:8080/
       http://127.0.0.1
       http://[::1]:8080/   //IPv6 address must be enclosed in [], rfc2732
       @endcode
     *
     * @param loop If the loop parameter is set to nullptr, the client uses the
     * HttpAppFramework's event loop, otherwise it runs in the loop identified
     * by the parameter.
     *
     * @note
     * Don't add path and parameters in hostString, the request path and
     * parameters should be set in HttpRequestPtr when calling the sendRequest()
     * method.
     *
     */
    static HttpClientPtr newHttpClient(const std::string &hostString,
                                       trantor::EventLoop *loop = nullptr);

    virtual ~HttpClient()
    {
    }

  protected:
    HttpClient() = default;
};

}  // namespace drogon
