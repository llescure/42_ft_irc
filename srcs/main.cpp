/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:43:35 by twagner           #+#    #+#             */
/*   Updated: 2022/07/19 11:57:26 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <cstdlib>
#include "../includes/irc.hpp"
#include "../includes/utils.hpp"

#define DEF_PORT 6667
#define DEF_PASS "changeme"

int main(int ac, char **av)
{
    // parameters
    int         port = DEF_PORT;
    std::string password = DEF_PASS;
    char        *end;

    // basic using parameters ------------------------------------------------ /
    // (add more control later)
    if (ac != 3)
        return (print_error("Parameters error", 1, false));
    port = static_cast<int>(strtol(av[1], &end, 10));
    password = av[2]; 

    // server call ----------------------------------------------------------- /
    return (server(port, password));
}
