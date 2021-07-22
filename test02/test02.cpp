#include <iostream>
#include <stdio.h>
#include <string.h>
#define CURL_STATICLIB 
#include <curl/curl.h>
#include "WebRequest.h"
#include<json-c/json.h>

/* POST data for connect */
static char data[] = "{ \"ActionName\": \"Connect\", \"Input\": { \"EntityName\": \"Credential\", \"Fields\": [{ \"Key\": \"DomainName\", \"Value\": \"D1\"},{ \"Key\": \"UserName\", \"Value\": \"Anubhav\"},{ \"Key\": \"Password\", \"Value\": \"ErasPaas\"}] }}";

int main(int argc, char** argv)
{
    struct WriteThis wt;

    wt.readptr = data;
    wt.sizeleft = strlen(data);

    WebRequest w1;
    struct WriteThis rt = w1.perform(wt);
    
    struct json_object* parsed_json;
    struct json_object* ErrorMessage;
    struct json_object* Output;

   // std::cout << rt.readptr<<std::endl;
    parsed_json = json_tokener_parse(rt.readptr);
   
    json_object_object_get_ex(parsed_json, "ErrorMessage", &ErrorMessage);
    json_object_object_get_ex(parsed_json, "Output", &Output);
   
    if (ErrorMessage != nullptr) {
        printf("ErrorMessage: %s\n", json_object_get_string(ErrorMessage));
        free(rt.readptr);
        return 0;
    }

    std::string sessionId = json_object_get_string(Output);
    std::cout << "SessionId: " << sessionId << std::endl;
  
 /*   std::string data2 = "{ \"ActionName\": \"CreateRecord\", \"SessionId\": \"" + sessionId + "\", \"Input\": { \"EntityName\": \"Student\", \"Fields\": [{ \"Key\": \"Name\", \"Value\": \"Pramanik\"},{ \"Key\": \"Roll\", \"Value\": \"01\"},{ \"Key\": \"Age\", \"Value\": \"21\"}] }}";
    int len2 = data2.length();
    char* data2Array = new char[len2 + 1];
    std::copy(data2.begin(), data2.end(), data2Array);
    data2Array[len2] = '\0';
    struct WriteThis wt2;

    wt2.readptr = data2Array;
    wt2.sizeleft = len2;

    WebRequest w2;
    struct WriteThis rt2 = w2.perform(wt2);

    parsed_json = json_tokener_parse(rt2.readptr);

    json_object_object_get_ex(parsed_json, "ErrorMessage", &ErrorMessage);
    json_object_object_get_ex(parsed_json, "Output", &Output);

    if (ErrorMessage != nullptr) {
        printf("ErrorMessage: %s\n", json_object_get_string(ErrorMessage));
        free(rt.readptr);
        return 0;
    }

    std::string recordId = json_object_get_string(Output);
    std::cout << "RecordId: " << recordId << std:: endl;
    */
    //update Record
  /*  std::string studentId = "3c8a82c0-bc48-4f48-a5e8-2c2df404a377";

    std::string data3 = "{ \"ActionName\": \"UpdateRecord\", \"SessionId\": \"" + sessionId + "\", \"Input\": { \"EntityName\": \"Student\", \"Fields\": [{ \"Key\": \"StudentId\", \"Value\": \"" + studentId + "\"}, { \"Key\": \"Name\", \"Value\": \"Aditya Pramanik\"},{ \"Key\": \"Roll\", \"Value\": \"101\"},{ \"Key\": \"Age\", \"Value\": \"20\"}] }}";
    int len3 = data3.length();
    char* data3Array = new char[len3 + 1];
    std::copy(data3.begin(), data3.end(), data3Array);
    data3Array[len3] = '\0';
    struct WriteThis wt3;

    wt3.readptr = data3Array;
    wt3.sizeleft = len3;

    WebRequest w3;
    struct WriteThis rt3 = w3.perform(wt3);

    parsed_json = json_tokener_parse(rt3.readptr);

    json_object_object_get_ex(parsed_json, "ErrorMessage", &ErrorMessage);
    json_object_object_get_ex(parsed_json, "Output", &Output);

     if (ErrorMessage != nullptr) {
        printf("ErrorMessage: %s\n", json_object_get_string(ErrorMessage));
        free(rt3.readptr);
        return 0;
    } 
    std::cout << "Successfully Updated the Record with RecordId: " << std::endl; 
    */
  
    /* 
      
    // Retrieve Record 
    std::string studentId = "3c8a82c0-bc48-4f48-a5e8-2c2df404a377";

    std::string data3 = "{ \"ActionName\": \"RetrieveRecord\", \"SessionId\": \"" + sessionId + "\", \"Input\": { \"EntityName\": \"Student\", \"Fields\": [{ \"Key\": \"StudentId\", \"Value\": \"" + studentId + "\"}, { \"Key\": \"Columns\", \"Value\": \"Name, Roll, Age\" }] }}";
    int len3 = data3.length();
    char* data3Array = new char[len3 + 1];
    std::copy(data3.begin(), data3.end(), data3Array);
    data3Array[len3] = '\0';
    struct WriteThis wt3;

    wt3.readptr = data3Array;
    wt3.sizeleft = len3;

    WebRequest w3;
    struct WriteThis rt3 = w3.perform(wt3);

    parsed_json = json_tokener_parse(rt3.readptr);

    json_object_object_get_ex(parsed_json, "ErrorMessage", &ErrorMessage);
    json_object_object_get_ex(parsed_json, "Output", &Output);

    if (ErrorMessage != nullptr) {
        printf("ErrorMessage: %s\n", json_object_get_string(ErrorMessage));
        free(rt3.readptr);
        return 0;
    }
    std::cout << "Successfully Updated the Record" << std::endl;
    printf("Output: %s\n", json_object_get_string(Output));
    */

    std::string studentId = "3c8a82c0-bc48-4f48-a5e8-2c2df404a377";

    std::string data3 = "{ \"ActionName\": \"DeleteRecord\", \"SessionId\": \"" + sessionId + "\", \"Input\": { \"EntityName\": \"Student\", \"Fields\": [{ \"Key\": \"StudentId\", \"Value\": \"" + studentId + "\"}, { \"Key\": \"Columns\", \"Value\": \"Name, Roll, Age\" }] }}";
    int len3 = data3.length();
    char* data3Array = new char[len3 + 1];
    std::copy(data3.begin(), data3.end(), data3Array);
    data3Array[len3] = '\0';
    struct WriteThis wt3;

    wt3.readptr = data3Array;
    wt3.sizeleft = len3;

    WebRequest w3;
    struct WriteThis rt3 = w3.perform(wt3);

    parsed_json = json_tokener_parse(rt3.readptr);

    json_object_object_get_ex(parsed_json, "ErrorMessage", &ErrorMessage);
    json_object_object_get_ex(parsed_json, "Output", &Output);

    if (ErrorMessage != nullptr) {
        printf("ErrorMessage: %s\n", json_object_get_string(ErrorMessage));
        free(rt3.readptr);
        return 0;
    }
    std::cout << "Successfully Updated the Record" << std::endl;
    printf("Output: %s\n", json_object_get_string(Output));

   // printf("%s\n", rt.readptr);
    free(rt.readptr);
   // free(rt2.readptr);
   // free(rt3.readptr);
    return 0;
}