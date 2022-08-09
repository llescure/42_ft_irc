# ft_irc

## What is it? ##

Create our own server that will be able to receive client connexions. In our case, netcat and irssi connexions.
With this server we will be able to communicate with different users.

## How does it work? ##

### Launching the server ###
`./ircserv [port number] [password]`

For example `./ircserv 6667 pwd`

### Launching a netcat client ###
`nc -C 127.0.0.1 6667`

We used the -C option since our reply messages end with \r\n as defined in the RFC 2812 standards.

We used 127.0.0.1 since our server is launched in localhost.

We used 6667 since it is the port, we specified, to our server to listen to.

**You will then need to do the authentification process**

`pass pwd`

`user lea 0 * :lea`

`nick lea`

Our user is now connected and known in the server as lea.

To understand more abour the authentification process please look [here](https://www.rfc-editor.org/rfc/rfc2812#section-3.1.1).

### Launching an irssi client ###
`irssi`

`/connect 127.0.0.1 6667 pwd`

The authentification process is automatically done by irssi.

Your user will be known in the server as plop.

## Commands we implemented ##

We implemented 24 commands.

### Server related commands ###
* DIE
* INFO
* MOTD
* PING
* PONG
* QUIT
* SERVICES
* TIME
* VERSION

### User related commands ###
* USER
* KILL
* MODE (B, i, o, r, s)
* NICK
* OPER
* PASS
* WHO
* WHOIS

### Channel related commands ###
* INVITE
* JOIN
* KICK
* LIST
* MODE (b, i, k, o)
* NAMES
* PART
* TOPIC

### Messages commands ###
* PRIVMSG (msg on irssi)
* NOTICE

## Bonus ##

### First bonus : file transfer ###
If you choose irssi as your reference client, it is automatically handled by irssi.

**Sending file to another client**

`/dcc send [nickname of user] [path of the file between quotes]`

For example `/dcc send plop_ "Documents/test.txt"`

**Receiving file from a client**

`/dcc get [nickname of user][name of the file between quotes]`

For example `/dcc get plop "test.text"`

DCC is handled as a PRIVMSG.


### Second bonus : implement a simple bot ###

We implemented it as a simple client using the command services. 

Our bot sends you some quote with command QUOTE and can give you the time with command TIME.

It is handled as a private conversation between the user and the bot.

`./ircbot [hostname] [password]`

## Ressources ##

* [General RFC](https://www.rfc-editor.org/rfc/rfc2812#section-3.1.1)
* [Channel related RFC](https://www.rfc-editor.org/rfc/rfc2811)
* [Tutorial on how to implement a server in french](http://vidalc.chez.com/lf/socket.html)
* [Website made by 42 students from Paris](https://ircgod.com/)
