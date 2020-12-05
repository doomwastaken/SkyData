#include <ClientSocked.h>
#include <iostream>
#include "ClientCommand.h"
#include "PushCommand.h"
#include "PopCommand.h"
#include "PostgressInternalDB.h"
#include "InternalDataBase.h"

Message create_message() {
    Devise devise = {"Android", "folder"};
    user_t user = {"NoName", "dog@cat", devise, 5};
    Message message = {100, MODIFIED, 0, 2, "NiceFile",
                       "txt", 100, "/www/tesla/", user};

    return message;
}
//
//bool operator==(const User &usr1, const User &usr2) {
//    if (usr1.user_name == usr2.user_name)
//        if (usr1.email == usr2.email)
//            if (usr1.quota_limit == usr2.quota_limit)
//                if (usr1.devise.device_name == usr2.devise.device_name)
//                    if (usr1.devise.sync_folder == usr2.devise.sync_folder)
//                        return 1;
//    return 0;
//}
//
//bool operator==(const Message &mes1, const Message &mes2) {
//    if (mes1.if_folder == mes2.if_folder)
//        if (mes1.status == mes2.status)
//            if (mes1.file_extension == mes2.file_extension)
//                if (mes1.file_name == mes2.file_name)
//                    if (mes1.file_path == mes2.file_path)
//                        if (mes1.times_modified == mes2.times_modified)
//                            if (mes1.version == mes2.version)
//                                if (mes1.user == mes2.user)
//                                    return 1;
//
//    return 0;
//}

int main() {
    std::string str = "dbname = postgres user = postgres password = Bars \
      hostaddr = 127.0.0.1 port = 5432";
   // PostgressInternalDB db1(str);
    //db1.
    InternalDataBase* db = new PostgressInternalDB();
    db->open(str);
    db->create_users_table();
    Message message = create_message();
    db->update(message);




    return 0;
}