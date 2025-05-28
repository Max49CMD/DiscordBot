#include "bot.hpp"

bot::bot(bool erase_CMD,
         const std::string& Token,
         uint64_t guild_id) : m_Token(Token), m_BOT(Token), m_Guild(guild_id) {}

int bot::init() {
    m_BOT.on_log(dpp::utility::cout_logger());

    sendMessage();

    m_BOT.on_ready([this](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            dpp::slashcommand greetingCommand("hi", "Say hello", m_BOT.me.id);
            dpp::slashcommand feelingCommand("feeling", "Check how the bot is feeling", m_BOT.me.id);

            m_BOT.guild_command_create(greetingCommand, m_Guild);
            m_BOT.guild_command_create(feelingCommand, m_Guild);

            if (m_Erase_CMD == true) {
                deleteAllCommands();
            }
        }
    });
    m_BOT.start(dpp::st_wait);
    return 0;
}

void bot::sendMessage() {
    m_BOT.on_slashcommand([this](const dpp::slashcommand_t& event) {
        std::string cmd = event.command.get_command_name();

        if (cmd == "hi") {
            event.reply("Hello!");
        }
        else if (cmd == "feeling") {
            event.reply("Feeling good");
        }
        else {
            event.reply("Something went wrong...");
        }
    });
}

void bot::deleteAllCommands() {
    if (dpp::run_once<struct clear_bot_commands>())
    {
        m_BOT.global_bulk_command_delete();
        m_BOT.guild_bulk_command_delete(m_Guild);
    }
}