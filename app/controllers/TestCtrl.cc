#include "TestCtrl.h"
void TestCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req,
                                      std::function<void (const HttpResponsePtr &)> &&callback)
{
    //write your application logic here
    //auto resp = HttpResponse::newHttpResponse();
    auto para = req->getParameters();
    drogon::HttpViewData data;
    data.insert("title", "ListParameters");
    data.insert("parameters", para);
    auto resp = HttpResponse::newHttpViewResponse("ListParameters.csp", data);
    callback(resp);
}