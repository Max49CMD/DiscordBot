#include "bot.hpp"

bot::bot(const std::string& bot_token) : m_BOT_TOKEN(bot_token), m_BOT(bot_token) {}

int bot::initBot() {
    m_BOT.on_log(dpp::utility::cout_logger());

    sendPong();

    m_BOT.on_ready([this](const dpp::ready_t& event) {
        dpp::slashcommand ping_cmd("ping", "Pong!", m_BOT.me.id);
        m_BOT.global_command_create(ping_cmd);
    });

    m_BOT.start(dpp::st_wait);
    return 0;
}

void bot::sendPong() {
    m_BOT.on_slashcommand([this](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });
}