#include "../../includes/channel.hpp"
#include "../../includes/replies.hpp"
#include "../../includes/utils.hpp"
#include "../../includes/commands.hpp"

int findUserOnChannel(std::deque<User *> userList, User *currentUser)
{
    std::deque<User *>::iterator it = userList.begin();

    for (; it != userList.end(); it++)
    {
        if (*it == currentUser)
            return (0);
    }
    return (-1);
}

int checkPartParameter(std::map<std::string, Channel *> channelList,
    std::string channelName, User *currentUser)
{
    if (channelName.empty() == true)
        return (-1);
    std::map<std::string, Channel *>::iterator it = findChannel(channelList, channelName);
    if (it == channelList.end())
        return (-2);
    if (findUserOnChannel(it->second->_users, currentUser) == -1)
        return (-3);
}

std::string part(const int fdUser, std::vector<std::string> parameter, Server *server)
{
    std::vector<std::string> channel;

    channel = getChannelKey(parameter);

    std::vector<std::string>::iterator it = channel.begin();
    // Check part parameters
    for (; it != channel.end(); it++)
    {
        if (checkPartParameter(server->_channelList, *it, server->getUserByFd()) == -1)
            return (reply(server, fdUser, "461", ERR_NEEDMOREPARAMS(std::string("PART"))));
        else if (checkPartParameter(server->_channelList, *it, server->getUserByFd()) == -2)
            return (reply(server, fdUser, "403", ERR_NOSUCHCHANNEL(*it)));
        else if (checkPartParameter(server->_channelList, *it, server->getUserByFd()) == -3)
            return (reply(server, fdUser, "442", (*it)));

        // Effectively part from channel
    }
}