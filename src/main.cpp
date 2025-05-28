#include "bot/bot.hpp"
#include "login/login.hpp"

int main() {
    /*
     * First param:
     *  - y/Y = All existing commands will be deleted/invisible.
     *  - n/N = Commands will be (re)registered as usual.
     *
     * Second param:
     *  - (Optional) Guild ID. Not required, but recommended for testing.
     *    I will use them for now
     *
     * Third param:
     *  - The bot token (required). You can get it from the Discord Developer Portal.
     *    There are plenty of tutorials explaining how to create a bot and get the token.
     *
     */

    const bool eraseCMD = askEraseCMD();
    const uint64_t guildID = askGuildID();
    const std::string token = askToken();

    bot myBot(
        eraseCMD,
        guildID,
        token);
    myBot.init();

    return EXIT_SUCCESS;
}