#include "gtest/gtest.h"
#include "Client_Sender.h"
#include "utils.h"


TEST(Client_Sender, ReturnedValue) {
Client_Sender client_sender;

Message message = create_message();

EXPECT_EQ(0, client_sender.send(message));
}
