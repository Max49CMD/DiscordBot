#include "bot.hpp"

bot::bot(const std::string& bot_token) : m_BOT_TOKEN(bot_token), m_BOT(bot_token) {}

int bot::initBot() {
    m_BOT.on_log(dpp::utility::cout_logger());

    //sendPong();

    bot::sendEmbends();

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


void bot::sendEmbends() {
    m_BOT.on_slashcommand([this](const dpp::slashcommand_t& event) {
        /* Check which command they ran */
        if (event.command.get_command_name() == "embed") {
            /* Create an embed */
            dpp::embed embed = dpp::embed()
                .set_color(dpp::colors::sti_blue)
                .set_title("Some name")
                .set_url("https://dpp.dev/")
                .set_author("Some name", "https://dpp.dev/", "https://dpp.dev/DPP-Logo.png")
                .set_description("Some description here")
                .set_thumbnail("https://dpp.dev/DPP-Logo.png")
                .add_field(
                    "Regular field title",
                    "Some value here"
                )
                .add_field(
                    "Inline field title",
                    "Some value here",
                    true
                )
                .add_field(
                    "Inline field title",
                    "Some value here",
                    true
                )
                .set_image("https://dpp.dev/DPP-Logo.png")
                .set_footer(
                    dpp::embed_footer()
                    .set_text("Some footer text here")
                    .set_icon("https://dpp.dev/DPP-Logo.png")
                )
                .set_timestamp(time(0));

            /* Create a message with the content as our new embed. */
            dpp::message msg(event.command.channel_id, embed);

            /* Reply to the user with the message, containing our embed. */
            event.reply(msg);
        }
    });
}