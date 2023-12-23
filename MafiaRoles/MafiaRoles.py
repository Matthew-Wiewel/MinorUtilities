import random

players_file = open("players.txt", "r")
roles_file = open("roles.txt", "r")

players_list = []
roles_list = []

for player in players_file:
    players_list.append(player)
for role in roles_file:
    roles_list.append(role)


num_players = len(players_list)

# make sure there wasn't an error in the files with mismatched number of players and roles
if num_players != len(roles_list):
    print(f"%d players and %d roles. \nThis is a mismatch. Exiting program. Fix the files!", num_players, len(roles_list))
    exit(1)

# only need to shuffle one of the two lists in order to randomize the assignments
# as I tend to list the roles by faction in roles.txt this also means that townies, mafia, etc have their players listed in a contiguous block
# rather than all over
random.shuffle(players_list)

# now we can print the players and their role assignments
for i in range(num_players):
    print(players_list[i] + " is a " + roles_list[i])



