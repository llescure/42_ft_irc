/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 07:46:38 by codespace         #+#    #+#             */
<<<<<<< HEAD:includes/Server.hpp
/*   Updated: 2022/07/21 12:59:44 by twagner          ###   ########.fr       */
=======
/*   Updated: 2022/07/21 11:24:02 by erecuero         ###   ########.fr       */
>>>>>>> f45dda1de83fff518358b5c97906643dee2e4201:srcs/server/Server.hpp
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include <vector>
#include <map>
#include "channel.hpp"
#include "user.hpp"

#define MAX_CMD_LEN 512

struct Command
{
    std::string                 command;
    std::string                 prefix;
    std::vector<std::string>    params;

    Command(std::string cmd, std::string prefix = std::string(), \
            std::vector<std::string> params = std::vector<std::string>());
    ~Command(){};
};

class Server
{
    public:
        // member type
        typedef void (*CmdFunction)(int, std::vector<std::string>, Server*); 

        // Constructors & destructor
        Server(int port, std::string password, std::string name = "Gunther");
        Server(Server const &src);
        ~Server(void){};

        // Operator overload
        Server  &operator=(Server const &rhs);
        
        // Getters
		int			getPort(void) const;
		std::string	getPassword(void) const;
		std::string	getName(void) const;
		std::string getHostname(void) const;
		User*		getUserByFd(const int &fd) const;

        // Member functions
        void    start(void);
        void    stop(void); // quit all clients with a message

        // exceptions
        class socketException : public std::exception
        { public: virtual const char *what() const throw(); };
        
        class bindException : public std::exception
        { public: virtual const char *what() const throw(); };

        class pollException : public std::exception
        { public: virtual const char *what() const throw(); };

        class pollWaitException : public std::exception
        { public: virtual const char *what() const throw(); };

        class pollAddException : public std::exception
        { public: virtual const char *what() const throw(); };

        class acceptException : public std::exception
        { public: virtual const char *what() const throw(); };
        
        class passwordException : public std::exception
        { public: virtual const char *what() const throw(); };

    private:
        // Cannot be default construct
        Server(void){};

        // Private member functions
        void    _initCommandList(void);
        int     _createSocket(void);
        void    _bindSocket(int sockfd, struct sockaddr_in *srv_addr);
        int     _createPoll(int sockfd);
        int     _pollWait(int pollfd, struct epoll_event **events, \
                           int max_events);
        void    _acceptConnection(int sockfd, int pollfd);
        void    _handleNewMessage(struct epoll_event event);
        void    _executeCommands(int fd, std::vector<Command> cmds);

        // Member attributes
        int         _port;
        std::string _password;
<<<<<<< HEAD:includes/Server.hpp
        std::string _hostname;
        std::string _name;
=======
        std::string _name;
		std::string _hostname;
>>>>>>> f45dda1de83fff518358b5c97906643dee2e4201:srcs/server/Server.hpp
        
        std::map<int, User *>               _userList;
        std::map<std::string, Channel *>    _channelList;
        std::map<std::string, CmdFunction>  _cmdList;
};

#endif
