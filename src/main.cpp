#include "bot.hpp"

int main() {
    /*
     * First param:
     *  - True = All existing commands will be deleted/invisible.
     *  - False = Commands will be (re)registered as usual.
     *
     * Second param:
     *  - The bot token (required). You can get it from the Discord Developer Portal.
     *    There are plenty of tutorials explaining how to create a bot and get the token.
     *
     * Third param:
     *  - (Optional) Guild ID. Not required, but recommended for testing.
     *    I will use them for now
     */

    bot myBot(
        false,
        1337,
        "Test1337");

    myBot.init();

    return EXIT_SUCCESS;
}