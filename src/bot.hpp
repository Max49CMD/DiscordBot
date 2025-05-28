#pragma once
#include <dpp/dpp.h>

class bot {
public:
    bot(bool erase_CMD, uint64_t guild_id, const std::string& Token);
    ~bot() = default;
    bot(bot &&) = delete;
    bot(const bot&) = delete;

public:
    int init();
    void sendMessage();
    void deleteAllCommands();

public:
    uint64_t get_Guild() const noexcept { return m_Guild; }
    const std::string& get_Token() const noexcept { return m_Token; };

private:
    const bool m_Erase_CMD;
    const uint64_t m_Guild;
    const std::string m_Token;
    dpp::cluster m_BOT;
};