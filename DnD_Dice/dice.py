import random
import math

""" 
I use this file primarily as a quick thing in the terminal as opposed to in other projects
so this string is just a quick and simple way for me to copy-paste as the import x as x
for the most common ones I use 
note: remember to have a \n at the end of the last one so it automatically enters
"""

# includes math import for math.sum([]) utility
import_string = "import math\n" +\
                "from dice import d100 as d100\n" +\
                "from dice import d20 as d20\n" +\
                "from dice import d12 as d12\n" +\
                "from dice import d10 as d10\n" +\
                "from dice import d8 as d8\n" +\
                "from dice import d6 as d6\n" +\
                "from dice import d4 as d4\n" +\
                "from dice import custom as custom\n" +\
                "from dice import lb as lb\n" +\
                "from dice import ss as ss\n" +\
                "from dice import talons as talons\n" +\
                "from dice import gen_abilities as gen_abilities\n" +\
                "\n\n\n" # to have some spacing on the command prompt

help_string = "each die defaults to one roll d20() return a 1d20 result\n" +\
                "you can add a parameter to do many rolls d20(5) returns an array for 5d20\n" +\
                "custom takes parameters of custom(#sides, #rolls). Like other dice, it defaults to 1 roll\n" +\
                "custom(14) returns 1d14 and custom(14, 3) returns an array for 3d14"

print("Imported the lib")
print(help_string + "\n\n")
print(import_string)

imports = lambda : print(import_string)
dice_help = lambda : print(help_string)


_max = lambda val1, val2 : val1 if val1 > val2 else val2
_min = lambda val1, val2 : val1 if val1 < val2 else val2
_custom_helper = lambda sides : random.randint(1,sides)
_d100_helper = lambda : random.randint(1,100)
_d20_helper = lambda : random.randint(1,20)
_d12_helper = lambda : random.randint(1,12)
_d10_helper = lambda : random.randint(1,10)
_d8_helper = lambda : random.randint(1,8)
_d6_helper = lambda : random.randint(1,6)
_d4_helper = lambda : random.randint(1,4)
adv = lambda the_die : _max(the_die(), the_die()) # in usage I don't like it, prefer rolling both and seeing them
dis = lambda the_die : _min(the_die(), the_die()) # see above
roll_with_modifier = lambda the_die, modifier : the_die() + modifier # in practive I found it more intuitive to just do a +mod instead of using this method
roll_custom_with_modifer = lambda sides, modifier : _custom_helper(sides) + modifier

d100 = lambda num_rolls=1 : _d100_helper() if num_rolls == 1 else [ _d100_helper() for i in range(num_rolls) ]
d20 = lambda num_rolls=1 : _d20_helper() if num_rolls == 1 else [ _d20_helper() for i in range(num_rolls) ]
d12 = lambda num_rolls=1 : _d12_helper() if num_rolls == 1 else [ _d12_helper() for i in range(num_rolls) ]
d10 = lambda num_rolls=1 : _d10_helper() if num_rolls == 1 else [ _d10_helper() for i in range(num_rolls) ]
d8 = lambda num_rolls=1 : _d8_helper() if num_rolls == 1 else [ _d8_helper() for i in range(num_rolls) ]
d6 = lambda num_rolls=1 : _d6_helper() if num_rolls == 1 else [ _d6_helper() for i in range(num_rolls) ]
d4 = lambda num_rolls=1 : _d4_helper() if num_rolls == 1 else [ _d4_helper() for i in range(num_rolls) ]
custom = lambda num_sides, num_rolls=1 : _custom_helper(num_sides) if num_rolls == 1 else [_custom_helper(num_sides) for i in range(num_rolls)]

def sum_rolls(die_type, num_rolls, modifier = 0, custom_sides = 0):
    """
    function to roll a die multiple times and get its sum
    arg order: die function, number rolls, modifier (default 0), num sides
    
    num side is default 0 to use die type as is, custom sides to 
    use a specific number of sides
    """
    sum = 0
    for i in range(num_rolls):
        if custom_sides == 0:
            sum += die_type()
        else:
            sum += die_type(custom_sides)
    return sum + modifier

def preroll_1s(die, num_1s_to_preroll):
    """
    sometimes you have a very important roll that you need to get a good result on
    in these situations it can be useful to "preroll" a die until it's rolled
    multiple 1's in a row. That way the odds of it rolling yet another 1 are
    extremely low and you'll be more likely to get a good roll when it's important
    (and don't you come in with your fancy statistics saying that rolling a die is an "independent event"
    this works and you can't convince me otherwise!)
    """
    num_rolled = 0
    while num_rolled < num_1s_to_preroll:
        if die() == 1:
            num_rolled += 1
        else:
            num_rolled = 0
    print("The 1s have pre-rolled out. Good luck, noble adventurer!")

"""
some methods I've added specialized to my current character of a ranger
"""

dex_mod = 4
archery_bonus =2
proficiency = 2

def lb(hunters_mark_active = False, shot="normal"):
    """
    default function for a longbow (my ranger)
    """
    # get to-hit rolls
    to_hit = 0 # initialize
    discarded_shot = 0
    if shot == "normal":
        to_hit = d20()
    else:
        roll1 = d20()
        roll2 = d20()
        if shot == "adv":
            to_hit = _max(roll1, roll2)
            discarded_shot = _min(roll1, roll2)
        else: #disadvantage case
            to_hit = _min(roll1, roll2)
            discarded_shot = _max(roll1, roll2)

    # get damage rolls
    bow_damage_array = [d8()] if to_hit != 20 else d8(2)
    hunters_mark_array = [0] if not hunters_mark_active else ( [d6()] if to_hit != 20 else d6(2) )

    # calculate damage
    bow_damage = int(math.fsum(bow_damage_array) + dex_mod)
    hunters_mark_damage = int(math.fsum(hunters_mark_array))
    total_damage = bow_damage + hunters_mark_damage
    
    # utility for printing with damage
    to_hit_string = str(to_hit) if shot == "normal" else ("max(" if shot == "adv" else "min(") + str(to_hit) + "," + str(discarded_shot) + ")"
    attack_bonus = dex_mod + proficiency + archery_bonus
    bow_damage_string = ("Damage: " if not hunters_mark_active else "Bow Damage: ") + (str(bow_damage_array[0]) if len(bow_damage_array) == 1 else str(bow_damage_array[0]) + " + " + str(bow_damage_array[1])) + " + " + str(dex_mod) +  " = " + str(bow_damage)
    hunters_mark_string = str(hunters_mark_array[0]) if len(hunters_mark_array) == 1 else str(hunters_mark_array[0]) + " + " + str(hunters_mark_array[1]) + " = " + str(hunters_mark_damage)
    total_damage_string = "Total Damage: " if not hunters_mark_active else "Total Damage: " + str(bow_damage) + " + " + str(hunters_mark_damage) + " = "

    # display nice and neat
    print("To Hit: ", to_hit_string, " + ", attack_bonus, " = ", to_hit+attack_bonus)
    print(bow_damage_string)
    if hunters_mark_active:
        print("Hunter's Mark: ", hunters_mark_string)
        print(total_damage_string, total_damage)

def ss():
    print("in progress")

def talons():
    print("in progress")

def gen_abilities():
    """
    generates ability scores for a character using 4d6 drop lowest
    TODO: add option to reroll ones. Both once and always
    """
    abilities = [ d6(4) for i in range(6) ]
    for ability in abilities:
        ability.sort()
    values = [ math.fsum(ability[1:]) for ability in abilities]
    return (abilities, values)