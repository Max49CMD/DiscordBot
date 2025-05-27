#pragma once
#include <dpp/dpp.h>

class bot {
public:
    bot(const std::string& bot_token);
    ~bot() = default;
    bot(bot &&) = delete;
    bot(const bot&) = delete;

public:
    int initBot();
    void sendPong();
public:
    const std::string& get_Token() const;

private:
    std::string m_BOT_TOKEN;
    dpp::cluster m_BOT;
};