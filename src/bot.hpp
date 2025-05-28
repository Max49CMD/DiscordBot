#pragma once
#include <dpp/dpp.h>

class bot {
public:
    bot(bool erase_CMD, const std::string& Token, uint64_t guild_id);
    ~bot() = default;
    bot(bot &&) = delete;
    bot(const bot&) = delete;

public:
    int init();
    void deleteAllCommands();
    void sendMessage();

public:
    uint64_t get_Guild_id() {return m_Guild;}
    std::string& get_Token() {return m_Token;};

private:
    bool m_Erase_CMD;
    uint64_t m_Guild;
    std::string m_Token;
    dpp::cluster m_BOT;
};