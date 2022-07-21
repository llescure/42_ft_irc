/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:19:33 by twagner           #+#    #+#             */
/*   Updated: 2022/07/21 13:08:17 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "Server.hpp"

# include <string>
# include <vector>

// Util functions
int                         printError(std::string message, int code, \
                                        bool with_errno);
std::vector<std::string>    splitBy(std::string str, std::string delimiter);
std::vector<Command>        splitCmds(std::vector<std::string> cmd_strings);
# include "replies.hpp"

// Util functions
int         print_error(std::string message, int code, bool with_errno);
std::string reply(Server *irc, const int &fd, std::string code, std::string replyMsg);
std::string get_next_tokn(std::string *str, std::string delimiter);

// Channel util functions
std::vector<std::string> splitByComma(std::string parameter);
bool                     isChannel(std::string channel_name);

#endif