#include "demo_v1_User.h"
using namespace demo::v1;
//add definition of your processing function here
void User::getParameters(const HttpRequestPtr &req,
                                   std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto para = req->getParameters();
    HttpViewData data;
    data.insert("title","ListParameters");
    data.insert("parameters",para);
    auto resp = HttpResponse::newHttpViewResponse("ListParameters.csp",data);
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_HTML);
    
    callback(resp);
};