#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <regex>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

const std::string input =
    R"(dull silver bags contain 2 striped magenta bags, 2 dark coral bags, 1 bright orange bag, 4 plaid blue bags.
dark plum bags contain 3 wavy teal bags.
wavy turquoise bags contain 3 bright salmon bags.
mirrored gold bags contain 3 wavy brown bags, 5 posh beige bags, 3 light crimson bags, 3 vibrant salmon bags.
drab green bags contain 4 dull white bags, 1 posh indigo bag.
faded lime bags contain 1 dim magenta bag, 1 wavy salmon bag, 4 dull purple bags.
mirrored blue bags contain 5 bright orange bags, 1 muted black bag, 2 muted brown bags, 2 vibrant gold bags.
faded crimson bags contain 4 wavy teal bags, 4 mirrored fuchsia bags, 3 plaid white bags.
faded magenta bags contain 2 clear orange bags, 5 dull green bags, 2 pale white bags.
pale red bags contain 5 shiny gold bags, 4 dull gold bags, 2 drab black bags.
dark coral bags contain 1 light turquoise bag.
faded chartreuse bags contain 4 shiny brown bags, 4 mirrored beige bags, 4 clear purple bags.
muted coral bags contain 4 pale coral bags, 4 plaid brown bags.
bright teal bags contain 5 striped blue bags, 4 faded orange bags, 2 faded crimson bags.
wavy green bags contain 5 dim chartreuse bags.
clear white bags contain 2 mirrored fuchsia bags.
clear aqua bags contain 1 faded beige bag.
vibrant yellow bags contain 5 posh brown bags.
pale lavender bags contain 1 striped beige bag, 2 striped cyan bags.
mirrored lime bags contain 3 bright orange bags.
faded tan bags contain 2 drab beige bags.
dark indigo bags contain 1 dark brown bag, 5 shiny beige bags, 1 vibrant indigo bag.
drab teal bags contain 2 vibrant fuchsia bags, 3 muted green bags, 5 dotted magenta bags, 2 shiny lavender bags.
shiny aqua bags contain 1 shiny gold bag, 4 clear white bags, 4 faded gold bags.
dull bronze bags contain 4 vibrant teal bags, 1 vibrant violet bag.
dark aqua bags contain 4 posh white bags.
dim coral bags contain 2 light yellow bags.
faded salmon bags contain 5 muted brown bags, 2 dotted red bags, 3 drab yellow bags, 4 dark red bags.
bright lavender bags contain 5 wavy maroon bags, 5 light brown bags, 5 bright silver bags, 1 dark gray bag.
mirrored cyan bags contain 4 dotted cyan bags, 5 striped orange bags, 1 vibrant gold bag.
drab aqua bags contain 3 striped black bags, 4 dark salmon bags, 1 drab white bag, 4 faded crimson bags.
striped purple bags contain 5 faded yellow bags, 2 faded brown bags.
drab fuchsia bags contain 4 vibrant violet bags, 5 mirrored yellow bags.
shiny red bags contain 3 faded cyan bags, 1 dull beige bag, 1 shiny blue bag, 5 dull cyan bags.
mirrored teal bags contain 4 clear brown bags, 5 light bronze bags, 3 light teal bags, 2 pale tomato bags.
dotted orange bags contain 3 dull white bags, 2 wavy blue bags.
dotted lavender bags contain 1 vibrant aqua bag, 4 shiny magenta bags, 3 dull plum bags.
pale crimson bags contain 4 muted cyan bags, 1 posh brown bag, 3 light magenta bags.
shiny black bags contain 4 vibrant chartreuse bags, 1 mirrored yellow bag, 3 posh brown bags, 5 vibrant violet bags.
clear bronze bags contain 5 dull violet bags, 3 pale plum bags.
striped lavender bags contain 1 dark plum bag, 2 striped yellow bags.
plaid indigo bags contain 2 plaid chartreuse bags.
shiny teal bags contain 4 wavy gray bags, 4 drab teal bags, 1 dark silver bag.
dull turquoise bags contain 1 wavy gray bag.
striped brown bags contain 1 striped olive bag, 1 wavy olive bag, 5 posh brown bags.
dotted magenta bags contain 4 drab silver bags, 3 light olive bags, 1 bright tan bag, 4 dull gold bags.
plaid yellow bags contain 5 drab black bags, 1 wavy lavender bag, 1 drab silver bag.
muted blue bags contain 5 posh aqua bags.
shiny olive bags contain 4 dark salmon bags, 1 faded gold bag, 3 drab chartreuse bags, 4 dotted yellow bags.
vibrant lime bags contain 4 shiny aqua bags, 1 bright maroon bag, 4 striped orange bags.
dim crimson bags contain 5 faded crimson bags.
vibrant gray bags contain 1 mirrored coral bag, 5 wavy beige bags, 3 drab turquoise bags.
posh chartreuse bags contain 3 light plum bags, 2 pale green bags, 5 drab white bags.
striped beige bags contain 5 dull red bags, 5 drab salmon bags, 3 vibrant salmon bags.
dotted tan bags contain 4 wavy crimson bags, 4 shiny orange bags, 1 drab turquoise bag.
vibrant aqua bags contain 1 vibrant gray bag, 5 light violet bags, 3 dim yellow bags.
faded turquoise bags contain 2 faded yellow bags, 4 mirrored coral bags.
mirrored purple bags contain 3 pale orange bags.
dim white bags contain 1 drab turquoise bag.
bright purple bags contain 5 muted chartreuse bags, 1 dotted yellow bag, 3 bright salmon bags.
drab red bags contain 1 mirrored magenta bag.
clear coral bags contain 4 drab black bags, 3 dark black bags.
mirrored orange bags contain 1 muted chartreuse bag.
wavy cyan bags contain 3 posh lime bags, 4 dark magenta bags, 4 vibrant turquoise bags.
pale magenta bags contain 4 vibrant turquoise bags, 3 clear gold bags.
posh gold bags contain 5 dotted lime bags, 5 wavy silver bags, 4 muted crimson bags, 1 dull yellow bag.
clear silver bags contain 1 drab indigo bag.
faded violet bags contain 2 mirrored bronze bags.
muted turquoise bags contain 2 plaid green bags, 2 light yellow bags, 4 dark violet bags.
striped bronze bags contain 4 striped white bags, 1 dim yellow bag, 5 clear aqua bags.
muted aqua bags contain 5 plaid green bags.
wavy teal bags contain no other bags.
pale black bags contain 5 dark salmon bags.
clear gold bags contain 2 plaid white bags, 5 drab coral bags, 5 pale coral bags.
muted chartreuse bags contain 5 faded crimson bags.
dotted fuchsia bags contain 1 plaid brown bag, 1 dark violet bag.
bright tomato bags contain 1 bright blue bag.
dim bronze bags contain 1 dotted green bag, 5 pale violet bags, 4 vibrant chartreuse bags, 3 striped yellow bags.
bright beige bags contain 1 drab blue bag.
vibrant olive bags contain 3 dotted olive bags.
clear tomato bags contain 1 light gray bag, 2 light turquoise bags, 2 striped yellow bags.
mirrored beige bags contain 3 light coral bags, 2 bright teal bags, 1 wavy magenta bag.
shiny gold bags contain 3 pale silver bags, 3 mirrored yellow bags, 2 shiny black bags, 2 light magenta bags.
plaid aqua bags contain 4 plaid crimson bags, 4 dim gray bags, 3 plaid orange bags, 2 dotted blue bags.
light green bags contain 2 light violet bags, 5 striped violet bags, 5 drab brown bags, 4 dull white bags.
vibrant beige bags contain 3 posh violet bags, 2 plaid blue bags, 4 shiny lavender bags, 5 wavy orange bags.
drab orange bags contain 3 striped beige bags, 3 posh teal bags, 5 drab silver bags, 1 dark indigo bag.
shiny orange bags contain 3 dark aqua bags, 4 clear beige bags, 2 mirrored lime bags, 3 dark violet bags.
wavy maroon bags contain 3 vibrant chartreuse bags.
wavy olive bags contain 5 dark aqua bags, 1 light yellow bag, 1 shiny crimson bag.
dotted cyan bags contain 2 drab gold bags.
muted cyan bags contain 1 clear gold bag, 4 dark plum bags, 2 wavy lavender bags, 5 vibrant indigo bags.
posh cyan bags contain 1 light fuchsia bag, 1 dark maroon bag.
faded bronze bags contain 2 muted salmon bags, 4 dim violet bags, 5 dark tan bags, 3 vibrant white bags.
pale green bags contain 4 muted turquoise bags, 1 vibrant green bag, 1 drab white bag.
clear brown bags contain 4 wavy teal bags, 4 drab violet bags.
striped salmon bags contain 5 mirrored orange bags, 1 shiny yellow bag, 1 muted beige bag, 1 clear purple bag.
posh brown bags contain 3 posh white bags, 4 drab chartreuse bags, 5 dark violet bags, 4 wavy teal bags.
mirrored green bags contain 1 dim tan bag.
bright yellow bags contain 2 striped indigo bags, 2 dark silver bags.
wavy yellow bags contain 3 dotted gold bags, 3 posh green bags.
light chartreuse bags contain 3 faded blue bags, 3 mirrored yellow bags, 3 shiny plum bags, 4 light red bags.
dark lime bags contain 5 vibrant chartreuse bags, 2 clear brown bags, 1 posh brown bag.
muted magenta bags contain 4 shiny silver bags, 2 dotted yellow bags, 4 pale fuchsia bags, 5 muted tan bags.
light plum bags contain 4 drab gold bags.
dim tomato bags contain 1 light silver bag.
pale lime bags contain 4 dull blue bags.
dim black bags contain 1 dark plum bag, 1 dull crimson bag, 5 wavy white bags, 2 plaid chartreuse bags.
muted teal bags contain 3 dim black bags, 4 mirrored lavender bags, 5 dull indigo bags, 3 clear red bags.
muted purple bags contain 1 mirrored red bag.
dull coral bags contain 5 pale teal bags, 2 faded cyan bags, 4 pale black bags, 2 muted olive bags.
vibrant red bags contain 4 light teal bags, 5 shiny fuchsia bags, 1 drab purple bag, 2 muted olive bags.
mirrored tomato bags contain 4 posh brown bags.
shiny coral bags contain 5 clear turquoise bags, 2 wavy salmon bags, 1 drab brown bag.
wavy indigo bags contain 1 vibrant brown bag, 2 dim turquoise bags, 1 posh violet bag, 1 plaid green bag.
dotted gold bags contain 5 pale aqua bags, 1 bright olive bag.
dotted violet bags contain 2 drab olive bags, 1 plaid cyan bag, 2 posh beige bags.
pale fuchsia bags contain 5 faded beige bags, 5 dark purple bags.
shiny chartreuse bags contain 1 striped tan bag, 5 pale tomato bags.
clear gray bags contain 1 bright fuchsia bag, 4 dotted olive bags, 2 light teal bags, 4 shiny magenta bags.
vibrant tomato bags contain 1 clear crimson bag, 3 pale purple bags, 3 faded gray bags.
light orange bags contain 5 plaid brown bags.
shiny tomato bags contain 3 light olive bags, 5 dim silver bags, 3 posh violet bags, 2 striped lavender bags.
faded green bags contain 2 dotted gold bags, 1 dark plum bag, 1 dull gray bag, 5 dark brown bags.
dim gray bags contain 5 muted white bags, 2 mirrored yellow bags, 1 muted tomato bag.
faded black bags contain 3 faded teal bags, 3 striped lavender bags, 2 striped blue bags, 4 muted lavender bags.
clear lime bags contain 3 mirrored yellow bags, 1 light yellow bag.
dark silver bags contain 4 wavy orange bags, 2 muted green bags.
plaid black bags contain 3 wavy indigo bags, 1 pale red bag.
mirrored black bags contain 5 dull black bags, 4 clear coral bags, 1 wavy olive bag, 4 dull silver bags.
light coral bags contain 5 drab black bags, 1 dark magenta bag, 1 drab teal bag, 1 mirrored crimson bag.
shiny yellow bags contain 5 faded indigo bags.
posh plum bags contain 3 faded maroon bags, 2 vibrant indigo bags, 1 bright turquoise bag.
faded olive bags contain 1 vibrant gray bag, 4 drab teal bags, 5 wavy teal bags.
dim plum bags contain 1 plaid white bag, 4 wavy beige bags, 3 wavy green bags.
muted tomato bags contain 5 dotted red bags, 1 drab purple bag, 1 light orange bag.
clear fuchsia bags contain 1 mirrored olive bag, 2 faded salmon bags.
striped violet bags contain 2 light olive bags, 1 plaid olive bag, 5 light white bags.
dim aqua bags contain 2 vibrant purple bags, 5 drab silver bags.
striped crimson bags contain 5 muted coral bags.
bright indigo bags contain 3 muted gold bags.
dotted black bags contain 4 shiny crimson bags, 5 dark salmon bags, 5 faded crimson bags, 2 vibrant magenta bags.
faded indigo bags contain 1 drab tomato bag.
bright bronze bags contain 1 wavy lime bag, 4 pale violet bags.
drab turquoise bags contain 2 drab gold bags, 2 vibrant gold bags, 4 pale tomato bags.
wavy black bags contain 2 dotted brown bags, 1 light salmon bag.
posh green bags contain 1 striped olive bag, 5 vibrant turquoise bags, 4 pale coral bags.
clear green bags contain 4 dull bronze bags, 4 shiny crimson bags, 1 light white bag.
dull chartreuse bags contain 2 dim aqua bags, 3 shiny black bags.
drab lime bags contain 1 wavy chartreuse bag, 4 mirrored chartreuse bags, 1 posh olive bag, 5 mirrored lavender bags.
bright tan bags contain 4 muted tan bags, 5 shiny gold bags, 1 mirrored red bag, 3 dull crimson bags.
dim maroon bags contain 3 clear red bags, 5 dark brown bags, 2 bright maroon bags, 1 muted teal bag.
drab tomato bags contain 4 dim orange bags, 2 mirrored violet bags, 3 faded purple bags.
muted gold bags contain 1 dim cyan bag.
striped white bags contain 1 plaid white bag, 1 posh purple bag, 3 muted cyan bags, 2 pale crimson bags.
wavy beige bags contain 2 plaid white bags, 3 dark brown bags.
vibrant turquoise bags contain 2 muted turquoise bags, 3 plaid green bags, 1 shiny crimson bag.
dark fuchsia bags contain 1 pale purple bag, 1 dim fuchsia bag, 3 light teal bags, 3 vibrant magenta bags.
dotted aqua bags contain 1 bright white bag, 5 clear gold bags, 5 clear tomato bags.
faded silver bags contain 1 light lime bag, 4 wavy gold bags.
faded brown bags contain 4 light aqua bags.
bright gray bags contain 3 faded red bags, 2 muted plum bags, 1 wavy brown bag.
wavy tan bags contain 1 pale maroon bag, 5 posh black bags.
bright blue bags contain 5 posh purple bags.
striped gold bags contain 4 dull tan bags, 1 shiny crimson bag, 2 clear blue bags.
bright magenta bags contain 4 shiny orange bags.
dotted brown bags contain 4 faded teal bags, 5 mirrored coral bags.
muted silver bags contain 5 striped black bags, 3 faded beige bags, 4 plaid crimson bags, 2 wavy brown bags.
wavy purple bags contain 1 dim brown bag, 1 bright yellow bag, 5 shiny lime bags.
dull plum bags contain 1 posh black bag, 4 vibrant fuchsia bags, 5 dull bronze bags.
dotted red bags contain 5 striped tomato bags, 4 shiny orange bags, 4 clear magenta bags, 5 pale coral bags.
light violet bags contain 2 bright beige bags, 5 mirrored plum bags, 3 wavy fuchsia bags, 1 clear tan bag.
dark teal bags contain 3 dull gray bags, 2 dark aqua bags, 1 clear beige bag.
light fuchsia bags contain 2 muted silver bags, 2 striped beige bags.
posh blue bags contain 5 striped olive bags, 5 dim coral bags.
light black bags contain 2 drab coral bags, 2 shiny indigo bags.
pale chartreuse bags contain 5 pale tomato bags.
drab gold bags contain 1 faded gold bag, 5 shiny gold bags.
posh bronze bags contain 2 drab aqua bags, 5 pale gray bags.
light tomato bags contain 5 wavy lime bags.
dull tan bags contain 3 drab blue bags, 4 dull green bags, 4 clear violet bags.
muted beige bags contain 5 clear white bags, 5 faded crimson bags.
faded fuchsia bags contain 5 plaid purple bags, 1 shiny silver bag, 4 muted violet bags.
bright green bags contain 5 dim teal bags, 5 shiny crimson bags, 5 clear crimson bags.
mirrored fuchsia bags contain 4 posh white bags, 5 wavy teal bags, 2 dark violet bags.
vibrant plum bags contain 2 posh yellow bags.
plaid bronze bags contain 4 dotted coral bags, 4 dull green bags, 2 plaid chartreuse bags.
plaid fuchsia bags contain 5 bright white bags.
dull red bags contain 2 mirrored fuchsia bags, 3 vibrant violet bags, 2 bright olive bags, 1 dim orange bag.
faded gray bags contain 1 dull purple bag, 2 posh salmon bags.
wavy plum bags contain 4 pale violet bags, 3 striped magenta bags, 4 pale red bags.
dark crimson bags contain 4 dim yellow bags, 1 dotted purple bag, 2 wavy indigo bags, 4 clear black bags.
pale cyan bags contain 5 shiny coral bags, 4 shiny beige bags, 2 plaid olive bags.
dull violet bags contain 3 wavy olive bags, 1 dull gray bag, 5 vibrant turquoise bags, 1 plaid purple bag.
wavy chartreuse bags contain 1 dotted magenta bag, 3 bright orange bags, 1 mirrored red bag.
dark cyan bags contain 5 dotted turquoise bags, 1 clear purple bag, 1 dim teal bag.
posh coral bags contain 3 muted bronze bags.
pale yellow bags contain 1 drab tomato bag.
plaid turquoise bags contain 1 muted gray bag.
dotted purple bags contain 5 posh silver bags, 4 dark salmon bags.
light indigo bags contain 4 mirrored red bags, 4 light olive bags.
faded plum bags contain 3 mirrored gold bags.
faded coral bags contain 5 dull tan bags.
clear indigo bags contain 5 mirrored magenta bags, 1 clear maroon bag, 1 bright blue bag, 5 light aqua bags.
dim cyan bags contain 5 plaid green bags.
dotted maroon bags contain 5 pale maroon bags, 2 dark indigo bags.
faded beige bags contain 1 plaid chartreuse bag.
striped indigo bags contain 1 dark gray bag, 3 drab olive bags.
clear yellow bags contain 4 dull gray bags, 1 muted green bag.
light lavender bags contain 4 pale coral bags, 2 light yellow bags, 2 light indigo bags.
light turquoise bags contain 5 pale fuchsia bags, 5 vibrant fuchsia bags, 5 vibrant magenta bags, 3 pale indigo bags.
light purple bags contain 2 light cyan bags.
bright gold bags contain 1 dark aqua bag.
muted bronze bags contain 2 light teal bags.
striped gray bags contain 2 light cyan bags, 1 pale black bag, 5 plaid plum bags.
wavy orange bags contain 2 pale coral bags, 2 dim coral bags.
)" +
    std::string(
        R"(wavy silver bags contain 2 posh white bags, 1 faded beige bag.
clear chartreuse bags contain 1 vibrant lime bag, 2 faded plum bags, 1 striped chartreuse bag, 5 clear maroon bags.
vibrant tan bags contain 3 striped lime bags, 4 pale maroon bags, 2 muted turquoise bags, 4 dark lime bags.
posh aqua bags contain 2 muted tan bags, 2 shiny blue bags, 2 posh purple bags.
bright orange bags contain no other bags.
drab coral bags contain no other bags.
light white bags contain 5 striped yellow bags.
wavy violet bags contain 1 pale silver bag, 2 shiny fuchsia bags, 1 vibrant violet bag, 1 shiny plum bag.
dark white bags contain 4 shiny maroon bags, 2 dim brown bags, 2 dark beige bags, 1 pale blue bag.
vibrant violet bags contain 4 striped blue bags, 1 mirrored lime bag, 1 posh white bag.
vibrant lavender bags contain 4 dotted magenta bags, 1 wavy red bag, 3 pale coral bags, 3 clear indigo bags.
dark purple bags contain 4 posh white bags.
mirrored lavender bags contain 5 clear brown bags, 2 faded gold bags.
striped silver bags contain 3 light yellow bags, 1 drab violet bag.
faded blue bags contain 3 muted violet bags, 4 wavy plum bags, 2 pale indigo bags, 1 wavy bronze bag.
drab cyan bags contain 4 dim tomato bags, 1 plaid lavender bag, 4 pale red bags, 2 drab olive bags.
clear lavender bags contain 3 wavy olive bags, 5 bright gray bags, 3 wavy beige bags, 2 dim violet bags.
striped aqua bags contain 3 mirrored lavender bags.
plaid tomato bags contain 2 posh cyan bags, 3 pale silver bags.
plaid salmon bags contain 1 muted lavender bag, 5 muted green bags, 3 bright aqua bags.
light blue bags contain 1 light white bag, 4 clear violet bags, 3 dark brown bags.
dark blue bags contain 5 posh aqua bags.
faded teal bags contain 3 light beige bags.
plaid chartreuse bags contain 4 wavy teal bags.
wavy gray bags contain 3 drab white bags, 2 muted lavender bags.
pale maroon bags contain 4 faded crimson bags, 4 vibrant chartreuse bags, 1 plaid green bag, 1 vibrant turquoise bag.
dark bronze bags contain 4 faded turquoise bags, 2 faded silver bags, 5 faded salmon bags.
pale coral bags contain 3 mirrored yellow bags, 4 dark plum bags, 2 dark aqua bags, 4 plaid white bags.
mirrored magenta bags contain 5 vibrant lime bags, 4 vibrant chartreuse bags, 3 striped aqua bags.
mirrored salmon bags contain 4 striped salmon bags, 1 posh tan bag, 3 faded bronze bags.
drab tan bags contain 5 vibrant violet bags.
vibrant indigo bags contain 1 pale coral bag, 1 light teal bag, 2 light magenta bags.
plaid lavender bags contain 1 striped silver bag, 1 clear lime bag.
muted plum bags contain 2 plaid crimson bags.
posh gray bags contain 5 mirrored lime bags.
clear maroon bags contain 5 wavy bronze bags, 3 dim gold bags, 2 muted beige bags, 5 posh coral bags.
striped maroon bags contain 2 dotted violet bags, 4 bright fuchsia bags, 4 striped aqua bags.
faded yellow bags contain 2 wavy teal bags, 3 wavy lavender bags.
posh black bags contain 1 drab silver bag, 2 clear white bags, 5 muted silver bags.
muted indigo bags contain 1 dark green bag, 1 plaid chartreuse bag, 3 bright indigo bags, 5 wavy silver bags.
wavy brown bags contain 5 faded red bags, 4 bright orange bags, 3 dim black bags.
vibrant coral bags contain 5 plaid white bags, 5 vibrant indigo bags.
wavy white bags contain 1 plaid green bag, 3 drab chartreuse bags, 1 posh white bag.
pale violet bags contain 2 shiny orange bags, 4 plaid crimson bags.
clear black bags contain 4 wavy blue bags, 5 plaid tan bags, 4 clear magenta bags.
faded aqua bags contain 2 wavy teal bags.
dotted green bags contain 5 shiny orange bags, 1 light magenta bag.
bright coral bags contain 2 shiny fuchsia bags, 4 light lime bags, 1 shiny gold bag.
vibrant fuchsia bags contain 1 vibrant chartreuse bag, 1 striped black bag.
dark turquoise bags contain 5 shiny salmon bags, 2 light lavender bags.
shiny green bags contain 1 pale silver bag, 4 dim red bags, 3 dark lime bags, 4 drab coral bags.
clear red bags contain 5 light teal bags, 5 posh brown bags.
dull gold bags contain 1 drab tan bag, 4 striped tomato bags, 5 pale maroon bags, 2 dim crimson bags.
mirrored red bags contain 3 shiny crimson bags, 4 plaid brown bags, 2 shiny black bags.
pale blue bags contain 1 wavy crimson bag, 4 faded beige bags, 4 shiny chartreuse bags.
clear beige bags contain 4 plaid crimson bags, 5 shiny crimson bags.
drab salmon bags contain 4 dim crimson bags, 3 light magenta bags, 1 clear violet bag.
vibrant magenta bags contain 4 dim black bags.
dark salmon bags contain 3 dull green bags, 4 faded red bags.
posh white bags contain no other bags.
light lime bags contain 5 dark aqua bags.
vibrant salmon bags contain 4 striped tomato bags, 4 clear aqua bags.
clear teal bags contain 3 striped gray bags.
plaid silver bags contain 3 vibrant violet bags, 2 muted magenta bags, 3 dark olive bags, 4 mirrored gold bags.
striped cyan bags contain 4 light gold bags, 2 dotted magenta bags.
wavy bronze bags contain 1 plaid crimson bag, 1 dull gray bag, 5 dull tan bags, 1 mirrored teal bag.
dim olive bags contain 4 vibrant lime bags, 2 shiny crimson bags, 2 muted turquoise bags.
dotted blue bags contain 4 vibrant gray bags, 2 shiny beige bags.
plaid blue bags contain 5 drab silver bags.
dark olive bags contain 1 pale coral bag, 4 vibrant indigo bags.
pale gray bags contain 3 dotted crimson bags, 1 striped magenta bag, 5 wavy white bags, 2 vibrant blue bags.
mirrored brown bags contain 2 bright cyan bags, 4 plaid brown bags, 5 faded turquoise bags.
wavy gold bags contain 1 wavy coral bag.
pale teal bags contain 3 vibrant magenta bags.
mirrored turquoise bags contain 4 mirrored olive bags, 5 bright yellow bags.
dark chartreuse bags contain 4 dotted cyan bags, 5 shiny turquoise bags, 5 vibrant salmon bags, 4 wavy yellow bags.
muted gray bags contain 3 dim orange bags.
posh turquoise bags contain 4 clear lavender bags, 5 dim coral bags, 2 striped salmon bags.
shiny cyan bags contain 4 striped gold bags.
drab olive bags contain 2 plaid cyan bags, 1 mirrored lime bag.
posh tomato bags contain 2 drab tan bags, 3 shiny orange bags.
muted fuchsia bags contain 1 pale salmon bag, 3 wavy violet bags, 3 mirrored maroon bags.
pale bronze bags contain 3 drab yellow bags, 3 muted chartreuse bags.
striped green bags contain 3 striped orange bags, 2 dull green bags, 3 vibrant tan bags.
faded orange bags contain 3 mirrored plum bags, 5 mirrored lime bags, 5 faded red bags.
dull aqua bags contain 2 striped coral bags.
dotted olive bags contain 4 faded salmon bags, 1 wavy green bag.
vibrant silver bags contain 4 mirrored yellow bags, 2 dotted salmon bags, 3 drab silver bags.
striped olive bags contain 1 mirrored fuchsia bag, 1 faded gold bag, 1 mirrored lavender bag.
dark violet bags contain no other bags.
mirrored olive bags contain 5 dull teal bags, 1 dim white bag.
plaid tan bags contain 4 pale gray bags, 2 dim crimson bags, 1 clear violet bag, 1 wavy lime bag.
pale tomato bags contain 5 posh green bags, 4 faded red bags.
dim turquoise bags contain 1 shiny gold bag, 5 drab blue bags.
muted lime bags contain 3 vibrant lime bags, 1 pale plum bag, 1 dark indigo bag.
drab beige bags contain 3 vibrant magenta bags.
posh beige bags contain 2 dark violet bags.
muted olive bags contain 2 pale brown bags, 5 light gray bags, 3 wavy green bags, 2 drab tan bags.
dim orange bags contain 1 clear lime bag, 4 faded beige bags, 2 mirrored fuchsia bags.
dull salmon bags contain 4 striped coral bags, 3 striped aqua bags.
dull maroon bags contain 3 clear brown bags, 5 dull magenta bags, 1 dim red bag.
mirrored coral bags contain 5 muted tan bags, 4 dotted magenta bags, 5 dim olive bags.
posh olive bags contain 4 dull magenta bags, 4 wavy blue bags, 2 drab yellow bags, 5 dotted gold bags.
mirrored violet bags contain 2 pale fuchsia bags.
drab bronze bags contain 4 drab chartreuse bags.
wavy fuchsia bags contain 2 dark gray bags, 5 muted silver bags.
pale plum bags contain 3 vibrant salmon bags, 5 drab chartreuse bags, 2 posh violet bags.
mirrored aqua bags contain 2 pale aqua bags.
bright silver bags contain 3 drab black bags, 5 dark salmon bags, 2 shiny beige bags, 2 posh lavender bags.
plaid lime bags contain 4 faded teal bags, 5 pale brown bags, 5 dim red bags.
dotted turquoise bags contain 3 dim olive bags, 2 mirrored blue bags, 3 dull lime bags, 4 vibrant lavender bags.
drab maroon bags contain 5 bright red bags.
wavy lavender bags contain 1 striped lime bag, 1 posh brown bag.
shiny beige bags contain 5 shiny aqua bags, 3 muted teal bags, 5 clear gold bags.
dark gold bags contain 4 clear maroon bags, 2 dotted maroon bags, 3 light red bags.
light aqua bags contain 2 dim red bags, 3 pale red bags.
posh teal bags contain 3 muted brown bags, 5 shiny gold bags, 5 dotted purple bags.
dull lavender bags contain 5 shiny blue bags.
dark tan bags contain 1 muted tan bag, 5 vibrant turquoise bags, 4 dark violet bags, 4 muted plum bags.
light beige bags contain 2 mirrored fuchsia bags, 1 drab chartreuse bag, 1 muted tan bag.
pale olive bags contain 3 clear brown bags.
dark maroon bags contain 5 dull plum bags, 3 muted green bags.
muted red bags contain 4 pale tan bags, 1 bright white bag.
light tan bags contain 3 light purple bags, 2 pale aqua bags, 3 wavy bronze bags.
clear magenta bags contain 3 vibrant chartreuse bags, 1 dim crimson bag.
dark orange bags contain 2 posh cyan bags, 1 wavy brown bag, 5 dull black bags.
dim lavender bags contain 5 drab fuchsia bags.
dotted beige bags contain 5 light blue bags, 4 plaid tan bags, 2 wavy maroon bags, 5 dim crimson bags.
dim green bags contain 3 plaid tan bags, 1 drab blue bag, 1 clear aqua bag.
plaid brown bags contain 3 muted turquoise bags, 4 drab chartreuse bags.
bright black bags contain 5 striped white bags.
plaid gold bags contain 3 shiny lime bags, 1 plaid maroon bag, 4 bright blue bags.
pale white bags contain 4 drab chartreuse bags, 3 pale tan bags, 5 pale aqua bags.
drab violet bags contain no other bags.
light magenta bags contain 3 faded crimson bags.
light gold bags contain 1 dim lavender bag, 3 light magenta bags, 5 drab gold bags.
plaid coral bags contain 1 vibrant salmon bag, 3 striped tomato bags, 3 posh blue bags.
dotted white bags contain 1 wavy lavender bag.
striped yellow bags contain 4 drab black bags, 2 faded red bags, 2 shiny gold bags, 4 dark aqua bags.
dark yellow bags contain 5 wavy bronze bags, 5 bright purple bags.
faded white bags contain 3 light tomato bags.
muted white bags contain 5 faded gold bags, 1 plaid magenta bag, 3 drab white bags, 5 dim brown bags.
faded red bags contain 1 posh brown bag, 2 muted turquoise bags, 3 plaid crimson bags, 4 shiny orange bags.
dark red bags contain 5 shiny salmon bags.
dull gray bags contain 2 posh white bags.
bright salmon bags contain 2 shiny aqua bags, 3 dotted crimson bags, 1 drab violet bag, 4 pale chartreuse bags.
mirrored chartreuse bags contain 1 vibrant magenta bag, 3 plaid salmon bags, 1 plaid chartreuse bag, 3 muted violet bags.
vibrant orange bags contain 5 posh yellow bags.
dark gray bags contain 1 plaid chartreuse bag, 2 drab violet bags, 1 bright chartreuse bag, 1 muted purple bag.
mirrored crimson bags contain 3 drab coral bags, 5 dull lime bags.
muted violet bags contain 3 dotted crimson bags, 3 light olive bags.
shiny brown bags contain 2 dark lavender bags, 2 vibrant yellow bags, 1 dark black bag, 2 drab olive bags.
muted green bags contain 1 dull cyan bag, 5 dull red bags, 4 pale chartreuse bags.
drab yellow bags contain 3 pale tomato bags.
dotted tomato bags contain 2 shiny magenta bags, 3 mirrored tomato bags, 5 plaid chartreuse bags.
plaid red bags contain 3 pale cyan bags.
bright red bags contain 1 shiny beige bag.
plaid purple bags contain 5 dull gold bags.
dark green bags contain 3 pale salmon bags, 3 dim brown bags, 2 wavy violet bags, 2 pale chartreuse bags.
plaid orange bags contain 1 vibrant chartreuse bag, 2 dotted coral bags, 1 posh teal bag.
plaid violet bags contain 1 shiny maroon bag.
posh tan bags contain 1 shiny beige bag, 2 dim magenta bags, 1 dark violet bag.
bright aqua bags contain 1 drab brown bag, 4 dotted purple bags.
vibrant white bags contain 4 light gray bags, 2 dark fuchsia bags, 1 pale cyan bag.
striped red bags contain 5 faded gold bags, 5 drab crimson bags, 3 faded turquoise bags.
dull purple bags contain 1 pale crimson bag.
shiny blue bags contain 1 pale violet bag, 5 mirrored plum bags, 3 posh white bags, 1 light yellow bag.
clear salmon bags contain 2 striped lime bags, 1 dull violet bag.
faded gold bags contain 3 light teal bags, 3 wavy teal bags.
mirrored yellow bags contain 2 muted turquoise bags, 4 drab chartreuse bags.
plaid gray bags contain 4 plaid plum bags.
plaid white bags contain no other bags.
drab black bags contain 2 mirrored yellow bags, 2 drab chartreuse bags, 1 shiny orange bag.
dotted chartreuse bags contain 2 vibrant cyan bags, 2 light salmon bags, 3 vibrant red bags, 5 light turquoise bags.
faded lavender bags contain 3 dark tomato bags, 5 muted lime bags, 4 light fuchsia bags, 4 dull lavender bags.
vibrant cyan bags contain 2 clear crimson bags, 3 pale orange bags, 4 dull indigo bags, 3 light red bags.
bright maroon bags contain 2 muted tan bags, 2 light teal bags.
drab silver bags contain 3 bright chartreuse bags, 4 pale crimson bags, 5 dotted crimson bags, 5 faded yellow bags.
drab purple bags contain 5 drab blue bags.
dim gold bags contain 1 bright cyan bag, 5 dull white bags, 3 vibrant blue bags.
dark beige bags contain 4 pale coral bags, 1 pale indigo bag.
dotted salmon bags contain 2 drab violet bags, 5 posh white bags.
vibrant crimson bags contain 5 faded teal bags, 3 dotted green bags, 1 clear maroon bag.
dim chartreuse bags contain 3 clear white bags.
bright violet bags contain 1 dim yellow bag, 1 muted purple bag, 4 muted teal bags, 5 striped cyan bags.
dim magenta bags contain 1 pale aqua bag, 4 pale maroon bags, 5 mirrored red bags, 4 drab yellow bags.
dim brown bags contain 5 faded salmon bags, 4 dotted magenta bags, 5 drab tomato bags, 2 faded teal bags.
shiny lime bags contain 5 dotted black bags, 4 plaid turquoise bags, 2 dim tomato bags, 2 clear magenta bags.
drab magenta bags contain 3 dark beige bags.
faded cyan bags contain 2 striped lime bags, 4 bright red bags.
dark brown bags contain 4 mirrored lime bags, 1 bright orange bag.
posh fuchsia bags contain 5 shiny gold bags, 5 pale salmon bags, 1 light coral bag, 1 mirrored plum bag.
shiny magenta bags contain 4 dark aqua bags.
dark lavender bags contain 1 pale purple bag, 3 vibrant yellow bags.
vibrant brown bags contain 2 posh teal bags, 1 wavy silver bag, 2 pale plum bags.
muted black bags contain 5 faded crimson bags, 3 dim crimson bags, 4 vibrant magenta bags.
muted brown bags contain 5 striped olive bags, 5 dark brown bags, 2 clear brown bags, 4 plaid white bags.
pale orange bags contain 4 bright blue bags, 3 dark aqua bags, 1 clear gold bag.
light cyan bags contain 3 muted silver bags.
drab white bags contain 2 drab tan bags, 2 striped tomato bags, 4 dull gray bags, 5 drab blue bags.
dim tan bags contain 3 mirrored bronze bags, 3 faded salmon bags, 4 drab purple bags.
dull tomato bags contain 3 clear lime bags.
wavy aqua bags contain 3 dotted orange bags, 5 shiny crimson bags.
shiny lavender bags contain 5 vibrant blue bags, 4 pale purple bags, 1 wavy bronze bag, 2 posh violet bags.
shiny white bags contain 5 faded blue bags, 5 pale cyan bags.
wavy blue bags contain 4 vibrant chartreuse bags, 4 plaid brown bags, 3 plaid white bags, 2 faded gold bags.
striped magenta bags contain 2 dark olive bags, 5 bright chartreuse bags.
vibrant black bags contain 4 plaid white bags, 2 dull silver bags, 5 striped purple bags, 1 dark plum bag.
dull green bags contain 2 dull crimson bags.
vibrant chartreuse bags contain 2 bright orange bags, 4 dark aqua bags.
dim violet bags contain 2 dark teal bags, 4 plaid brown bags, 4 mirrored yellow bags.
clear blue bags contain 5 posh maroon bags.
faded tomato bags contain 5 clear beige bags, 4 bright orange bags.
posh violet bags contain 3 clear gold bags.
striped tomato bags contain 2 shiny black bags.
muted crimson bags contain 4 light aqua bags, 3 dim gold bags.
clear tan bags contain 4 drab tomato bags, 4 mirrored bronze bags, 1 shiny chartreuse bag.
posh magenta bags contain 4 posh red bags, 3 light bronze bags.
)" ) +
    std::string(
        R"(dim blue bags contain 5 dim gray bags, 1 light turquoise bag, 5 muted bronze bags.
drab plum bags contain 1 vibrant plum bag, 4 striped coral bags.
pale silver bags contain 5 drab black bags.
posh purple bags contain 2 dark brown bags.
drab indigo bags contain 1 muted lavender bag, 2 posh salmon bags, 1 pale brown bag.
striped blue bags contain 4 wavy teal bags.
wavy magenta bags contain 1 dotted salmon bag, 1 drab black bag, 2 dull tan bags, 1 drab silver bag.
pale turquoise bags contain 4 dark lime bags, 4 drab maroon bags.
shiny tan bags contain 4 plaid coral bags, 3 dim black bags, 1 dull plum bag.
light teal bags contain 3 dark violet bags.
mirrored silver bags contain 1 striped salmon bag, 1 clear chartreuse bag, 2 clear orange bags, 2 posh aqua bags.
wavy coral bags contain 2 muted teal bags, 1 wavy white bag.
wavy crimson bags contain 1 shiny aqua bag, 3 muted beige bags.
shiny bronze bags contain 1 posh indigo bag, 5 wavy blue bags, 1 faded gold bag, 3 striped tomato bags.
shiny maroon bags contain 1 clear tomato bag, 1 wavy crimson bag.
bright turquoise bags contain 3 dull tan bags, 3 vibrant teal bags.
faded purple bags contain 1 plaid chartreuse bag.
bright white bags contain 2 faded gold bags.
clear orange bags contain 4 striped blue bags, 2 mirrored lime bags, 5 muted turquoise bags.
clear cyan bags contain 1 dim plum bag, 3 shiny brown bags, 1 muted purple bag, 2 plaid lime bags.
plaid teal bags contain 2 faded aqua bags, 4 wavy olive bags.
dotted lime bags contain 5 posh olive bags, 2 pale orange bags.
muted tan bags contain 1 dull gray bag, 2 dark aqua bags, 1 pale violet bag.
striped orange bags contain 3 mirrored lime bags, 2 dull crimson bags, 4 faded gold bags, 3 pale silver bags.
light olive bags contain 2 dark tan bags, 3 dim orange bags, 5 mirrored yellow bags.
plaid magenta bags contain 2 wavy orange bags, 1 wavy chartreuse bag, 5 striped coral bags.
dark magenta bags contain 3 bright white bags, 3 plaid purple bags, 3 striped black bags, 4 light beige bags.
dark black bags contain 3 pale tan bags, 4 mirrored orange bags, 3 dull teal bags.
posh orange bags contain 4 bright aqua bags, 1 dim crimson bag, 4 dim turquoise bags, 1 dotted bronze bag.
dull crimson bags contain 4 vibrant violet bags.
clear turquoise bags contain 1 muted brown bag, 2 dull yellow bags, 3 pale black bags, 1 plaid crimson bag.
vibrant blue bags contain 2 clear beige bags.
dull lime bags contain 4 shiny plum bags, 3 vibrant magenta bags, 3 dark olive bags.
drab brown bags contain 4 clear green bags.
mirrored plum bags contain 2 faded red bags.
shiny fuchsia bags contain 2 muted cyan bags, 4 dark aqua bags, 3 light olive bags, 2 clear gold bags.
vibrant purple bags contain 3 pale aqua bags, 3 dark lime bags, 1 bright chartreuse bag.
bright crimson bags contain 1 vibrant gold bag.
shiny plum bags contain 2 clear olive bags, 4 dark plum bags.
shiny crimson bags contain no other bags.
dull beige bags contain 1 mirrored coral bag.
dim salmon bags contain 1 clear tomato bag, 2 shiny teal bags, 4 plaid olive bags, 3 plaid purple bags.
muted maroon bags contain 2 muted violet bags, 4 dark white bags.
pale aqua bags contain 4 dark beige bags, 1 muted brown bag.
bright plum bags contain 4 dim black bags.
striped tan bags contain 3 bright orange bags, 3 dark violet bags, 4 drab blue bags, 2 vibrant lime bags.
clear crimson bags contain 3 wavy brown bags, 1 faded blue bag, 2 striped cyan bags.
dim indigo bags contain 3 dotted lime bags, 1 dotted purple bag.
pale tan bags contain 2 drab blue bags, 5 dim orange bags, 5 wavy olive bags, 3 striped tomato bags.
vibrant bronze bags contain 5 clear red bags, 5 posh red bags.
dotted bronze bags contain 1 light yellow bag.
wavy salmon bags contain 2 striped olive bags, 4 muted teal bags.
shiny turquoise bags contain 3 dark teal bags, 1 plaid yellow bag.
faded maroon bags contain 1 vibrant salmon bag, 5 dotted magenta bags, 1 faded tan bag, 5 striped tomato bags.
vibrant teal bags contain 4 light teal bags, 3 pale orange bags, 5 drab white bags.
vibrant gold bags contain 1 muted cyan bag, 2 mirrored plum bags, 1 drab coral bag, 4 dark lime bags.
bright cyan bags contain 2 muted silver bags, 5 plaid bronze bags, 3 light beige bags, 2 faded crimson bags.
shiny silver bags contain 4 mirrored fuchsia bags, 2 clear violet bags, 3 faded beige bags.
dark tomato bags contain 4 clear lime bags, 2 light beige bags, 3 bright turquoise bags.
mirrored indigo bags contain 5 posh chartreuse bags, 5 clear tomato bags.
dotted indigo bags contain 2 drab olive bags, 2 dim indigo bags, 5 dotted magenta bags.
shiny gray bags contain 4 muted chartreuse bags, 4 plaid gray bags, 3 dull red bags, 5 striped orange bags.
dim yellow bags contain 1 muted cyan bag, 4 mirrored fuchsia bags, 1 faded gold bag, 1 drab turquoise bag.
bright lime bags contain 5 shiny bronze bags, 3 wavy aqua bags, 4 plaid turquoise bags.
dotted gray bags contain 2 shiny gold bags.
striped black bags contain 1 wavy teal bag, 5 dim chartreuse bags, 4 mirrored lavender bags.
pale beige bags contain 2 posh black bags, 4 clear white bags.
posh indigo bags contain 5 plaid white bags.
dull blue bags contain 4 dark violet bags, 2 clear magenta bags, 4 dotted crimson bags.
mirrored white bags contain 5 faded yellow bags.
bright brown bags contain 3 pale gray bags.
light gray bags contain 3 clear magenta bags, 5 wavy brown bags, 3 dotted salmon bags.
muted orange bags contain 1 bright magenta bag, 1 bright plum bag.
clear purple bags contain 1 shiny gold bag, 1 dark white bag.
striped coral bags contain 5 pale gray bags, 3 wavy chartreuse bags.
plaid green bags contain no other bags.
plaid maroon bags contain 5 posh brown bags, 3 striped crimson bags, 4 plaid green bags.
light maroon bags contain 3 muted gray bags, 5 dull crimson bags, 2 shiny maroon bags.
pale purple bags contain 2 striped white bags, 3 plaid chartreuse bags, 1 mirrored lime bag.
muted yellow bags contain 5 vibrant purple bags, 1 dark teal bag.
plaid olive bags contain 1 light crimson bag, 1 faded gold bag, 1 vibrant blue bag.
dim beige bags contain 4 muted silver bags, 3 mirrored beige bags, 4 striped violet bags.
striped chartreuse bags contain 3 dull teal bags.
muted salmon bags contain 2 posh salmon bags, 2 posh silver bags.
dim red bags contain 2 drab blue bags, 4 plaid crimson bags, 3 vibrant gold bags.
dull magenta bags contain 5 faded crimson bags, 1 shiny orange bag, 1 dark tan bag.
plaid beige bags contain 1 vibrant turquoise bag.
striped teal bags contain 2 dim chartreuse bags, 4 dark green bags.
dotted plum bags contain 2 light cyan bags.
dotted yellow bags contain 5 posh black bags, 5 dull tan bags, 2 dull violet bags, 5 muted plum bags.
dotted coral bags contain 1 striped tomato bag, 2 light crimson bags, 3 clear violet bags.
dull fuchsia bags contain 3 plaid purple bags, 4 mirrored red bags.
dull yellow bags contain 5 vibrant violet bags, 2 dark olive bags.
dull white bags contain 5 posh olive bags, 5 pale tomato bags, 2 bright teal bags.
pale brown bags contain 3 dim crimson bags, 3 pale indigo bags, 1 dim chartreuse bag, 4 muted teal bags.
shiny violet bags contain 1 muted tomato bag, 2 dull yellow bags, 1 drab teal bag.
drab blue bags contain 3 vibrant gold bags, 4 drab black bags.
posh lavender bags contain 5 shiny plum bags, 3 drab salmon bags, 4 dim brown bags, 4 plaid blue bags.
dull teal bags contain 2 drab turquoise bags, 1 shiny crimson bag, 5 shiny aqua bags.
shiny purple bags contain 3 drab orange bags, 4 dark red bags, 4 vibrant fuchsia bags, 2 light fuchsia bags.
pale salmon bags contain 2 plaid chartreuse bags, 3 striped white bags.
posh silver bags contain 4 clear magenta bags, 5 light magenta bags.
light salmon bags contain 4 vibrant olive bags.
striped turquoise bags contain 1 faded magenta bag, 3 shiny indigo bags, 4 striped lavender bags.
dotted crimson bags contain 2 pale silver bags, 2 striped magenta bags, 1 striped white bag.
dull brown bags contain 5 clear crimson bags, 1 dotted green bag, 4 dull magenta bags, 3 dim tan bags.
plaid cyan bags contain 1 striped orange bag, 2 muted cyan bags.
muted lavender bags contain 5 mirrored fuchsia bags.
dim lime bags contain 1 muted black bag.
light bronze bags contain 1 dull crimson bag, 5 dim chartreuse bags.
dull olive bags contain 2 vibrant coral bags, 3 shiny teal bags, 4 plaid purple bags.
posh yellow bags contain 5 dark lime bags, 3 mirrored plum bags.
bright fuchsia bags contain 1 striped silver bag.
posh maroon bags contain 4 dotted magenta bags, 4 posh yellow bags, 2 drab beige bags.
posh salmon bags contain 2 muted green bags.
mirrored gray bags contain 4 striped silver bags.
dull cyan bags contain 2 bright orange bags, 4 dark plum bags.
light crimson bags contain 3 drab fuchsia bags, 3 bright blue bags, 1 dark purple bag.
light red bags contain 3 dim maroon bags, 4 muted green bags, 3 dotted olive bags.
dull indigo bags contain 2 plaid brown bags, 1 wavy white bag, 2 vibrant turquoise bags, 5 drab chartreuse bags.
drab crimson bags contain 2 vibrant salmon bags.
posh red bags contain 3 mirrored violet bags, 1 striped tomato bag, 2 striped olive bags.
drab chartreuse bags contain no other bags.
posh lime bags contain 3 drab violet bags, 1 bright coral bag.
wavy red bags contain 4 striped gray bags, 3 posh salmon bags, 1 dotted violet bag, 3 striped aqua bags.
striped fuchsia bags contain 3 bright crimson bags, 3 dark silver bags, 1 clear magenta bag, 3 drab salmon bags.
striped plum bags contain 2 drab tan bags, 5 pale gold bags, 1 dull white bag, 1 clear coral bag.
mirrored maroon bags contain 1 dark magenta bag, 1 plaid purple bag, 2 light gray bags.
shiny indigo bags contain 2 drab teal bags.
dim silver bags contain 1 striped aqua bag, 3 dull tan bags, 3 striped tan bags, 2 wavy maroon bags.
shiny salmon bags contain 5 faded beige bags.
dull black bags contain 3 vibrant plum bags, 2 plaid chartreuse bags, 1 muted brown bag, 2 clear tomato bags.
clear plum bags contain 3 striped maroon bags, 2 dark white bags.
vibrant green bags contain 5 light orange bags, 5 mirrored magenta bags, 3 bright teal bags, 2 striped brown bags.
drab gray bags contain 1 plaid maroon bag, 2 pale tan bags, 1 plaid white bag.
wavy lime bags contain 2 clear gold bags, 2 bright chartreuse bags, 1 faded crimson bag.
light silver bags contain 4 dim maroon bags, 1 mirrored teal bag.
light brown bags contain 5 muted magenta bags.
dim fuchsia bags contain 5 pale purple bags, 5 wavy orange bags, 5 clear lime bags.
vibrant maroon bags contain 4 light gray bags.
dim purple bags contain 2 muted white bags, 2 shiny aqua bags.
clear olive bags contain 3 bright olive bags.
drab lavender bags contain 4 mirrored crimson bags, 3 bright violet bags, 5 posh gold bags, 2 bright olive bags.
light yellow bags contain 1 posh brown bag, 2 pale violet bags.
plaid crimson bags contain 1 plaid green bag, 3 shiny crimson bags.
pale indigo bags contain 3 clear aqua bags, 2 pale silver bags.
mirrored bronze bags contain 4 muted tomato bags, 4 bright white bags, 1 faded crimson bag.
dim teal bags contain 1 muted salmon bag.
clear violet bags contain 2 dim coral bags, 2 faded beige bags.
dotted silver bags contain 2 posh plum bags, 4 pale chartreuse bags.
pale gold bags contain 2 vibrant gold bags, 1 dotted magenta bag.
posh crimson bags contain 4 dull yellow bags, 3 clear fuchsia bags.
dull orange bags contain 3 dull silver bags, 3 clear violet bags, 4 clear chartreuse bags, 3 faded salmon bags.
striped lime bags contain 5 mirrored plum bags, 4 faded gold bags, 3 wavy white bags, 3 light teal bags.
mirrored tan bags contain 4 dull silver bags, 4 light coral bags, 2 plaid lavender bags.
wavy tomato bags contain 4 clear orange bags, 5 shiny fuchsia bags, 3 light red bags.
dotted teal bags contain 5 dark salmon bags, 1 light indigo bag, 4 pale white bags, 5 clear olive bags.
bright olive bags contain 1 dark tan bag, 4 striped orange bags, 3 bright orange bags.
plaid plum bags contain 1 shiny maroon bag, 1 dotted coral bag.
bright chartreuse bags contain 2 wavy blue bags.)" );

const std::string part1SampleInput = R"(light red bags contain 1 bright white bag, 2 muted yellow bags.
dark orange bags contain 3 bright white bags, 4 muted yellow bags.
bright white bags contain 1 shiny gold bag.
muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.
shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.
dark olive bags contain 3 faded blue bags, 4 dotted black bags.
vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.
faded blue bags contain no other bags.
dotted black bags contain no other bags.)";

const std::string part2SampleInput = R"(shiny gold bags contain 2 dark red bags.
dark red bags contain 2 dark orange bags.
dark orange bags contain 2 dark yellow bags.
dark yellow bags contain 2 dark green bags.
dark green bags contain 2 dark blue bags.
dark blue bags contain 2 dark violet bags.
dark violet bags contain no other bags.)";

// This split function comes from https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
//
std::vector<std::string> split( const std::string& s, const char delimiter )
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream( s );
    while ( std::getline( tokenStream, token, delimiter ) )
    {
        tokens.push_back( token );
    }
    return tokens;
}

template<typename T>
void print( const T& container, const char suffix )
{
    std::cout << '{';
    bool isFirst = true;
    for ( const auto& element : container )
    {
        if ( isFirst )
        {
            std::cout << element;
            isFirst = false;
        }
        else
        {
            std::cout << ',' << element;
        }
    }
    std::cout << '}' << suffix;
}

const std::regex terminalRegex( R"((.*) bags contain no other bags.)" );
const std::regex containingRegex( R"((.*) bags contain (\d+.*))" );
const std::regex containedRegex( R"(\s*(\d+) (.+) bags?\.?)" );

struct Bag;

struct ChildBag
{
    ChildBag(const std::shared_ptr<Bag>& childBag, const int num)
        : pChildBag(childBag)
        , numberInParent(num)
    {}

    std::shared_ptr<Bag> pChildBag;
    int numberInParent;
};

struct Bag
{
    Bag( const std::string& bagColour )
        : colour( bagColour )
    {}

    bool contains(
        const std::vector<std::weak_ptr<Bag>>& bags,
        const std::shared_ptr<Bag>& pBag ) const
    {
        const auto iter =
            std::find_if( cbegin( bags ), cend( bags ), [&pBag]( const auto& pElement ) {
                return pElement.lock() == pBag;
            } );
        return iter != cend( bags );
    }

    bool contains(
        const std::vector<std::shared_ptr<ChildBag>>& childBags, const std::shared_ptr<Bag>& pBag ) const
    {
        const auto iter = std::find_if(
            cbegin( childBags ),
            cend( childBags ),
            [&pBag]( const std::shared_ptr<ChildBag>& pElement ) {
                return pElement->pChildBag == pBag;
            } );
        return iter != cend( childBags );
    }

    bool has_child( const std::shared_ptr<Bag>& pChild ) const
    {
        return contains( m_childBags, pChild );
    }

    void add_child( const std::shared_ptr<ChildBag>& pChild )
    {
        if ( !has_child( pChild->pChildBag ) )
        {
            m_childBags.emplace_back( pChild );
        }
    }

    bool has_parent( const std::shared_ptr<Bag>& pParent ) const
    {
        return contains( parentBags, pParent );
    }

    void add_parent( const std::shared_ptr<Bag>& pParent )
    {
        if ( !has_parent( pParent ) )
        {
            parentBags.emplace_back( pParent );
        }
    }

    std::string colour;
    std::vector<std::shared_ptr<ChildBag>> m_childBags = {};
    std::vector<std::weak_ptr<Bag>> parentBags = {};
};

struct Rules
{
    std::map<std::string, std::shared_ptr<Bag>> colourToBag;

    bool colour_exists( const std::string& colour ) const
    {
        return colourToBag.count( colour ) > 0;
    }
};

std::shared_ptr<Bag> create_bag_if_needed( const std::string& colour, Rules& rules )
{
    if ( !rules.colour_exists( colour ) )
    {
        auto pBag = std::make_shared<Bag>( colour );
        rules.colourToBag[colour] = pBag;
        return pBag;
    }
    else
    {
        return rules.colourToBag.at( colour );
    }
}

void parse_contained_bags(
    const std::string& containedBags, Rules& rules, const std::shared_ptr<Bag>& pParentBag )
{
    const auto individualBags = split( containedBags, ',' );

    for ( const auto& bag : individualBags )
    {
        std::smatch match;
        if ( std::regex_match( bag, match, containedRegex ) )
        {
            const auto colour = match[2].str();
            const auto numberInParent = std::stoi( match[1].str() );
            create_bag_if_needed( colour, rules );

            const auto& pChildBag = rules.colourToBag.at( colour );
            pChildBag->add_parent( pParentBag );
            pParentBag->add_child( std::make_shared<ChildBag>( pChildBag, numberInParent ));
        }
        else
        {
            std::cerr << "Failed to match contained regex for: " << bag << '\n';
        }
    }
}

void parse_line( const std::string& line, Rules& rules )
{
    std::smatch match;

    if ( std::regex_match( line, match, terminalRegex ) )
    {
        // This bag does not contain any other bags, so we just add it if it doesn't already exist.
        //
        create_bag_if_needed( match[1].str(), rules );

        return;
    }
    else if ( std::regex_match( line, match, containingRegex ) )
    {
        // This bag contains other bags. First we add this bag if it doesn't already exist, and then
        // we continue to parse the bags it contains.
        //
        const auto pParentBag = create_bag_if_needed( match[1].str(), rules );

        parse_contained_bags( match[2].str(), rules, pParentBag );
    }
    else
    {
        std::cerr << "Failed to match anything for line: " << line << '\n';
    }
}

void add_all_parents( std::set<std::string>& parentColours, const std::shared_ptr<Bag>& pBag )
{
    for ( const auto& pParent : pBag->parentBags )
    {
        const auto pSharedParent = pParent.lock();
        parentColours.insert( pSharedParent->colour );
        add_all_parents( parentColours, pSharedParent );
    }
}

void print_known_colours( const Rules& rules )
{
    std::for_each(
        cbegin( rules.colourToBag ),
        cend( rules.colourToBag ),
        []( const auto& colourToBag )
        {
            std::cout << colourToBag.first << '\n';
        } );
}

int count_contained_bags( const std::shared_ptr<ChildBag>& pBag )
{
    if ( pBag->pChildBag->m_childBags.empty() )
    {
        return pBag->numberInParent;
    }
    else
    {
        int containedBags = 0;
        for ( const auto& pChildBag : pBag->pChildBag->m_childBags )
        {
            containedBags += count_contained_bags( pChildBag );
        }
        return pBag->numberInParent * (containedBags + 1);
    }
}

int count_contained_bags( const std::string& bagColour, const Rules& rules )
{
    const auto& pRootBag = rules.colourToBag.at( bagColour );
    int containedBags = 0;
    for ( const auto& pChildBag : pRootBag->m_childBags )
    {
        containedBags += count_contained_bags( pChildBag );
    }

    return containedBags;
}

int main()
{
    const std::string colourOfInterest = "shiny gold";

    {
        const auto lines = split( input, '\n' );
        Rules rules;

        for ( const auto& line : lines )
        {
            parse_line( line, rules );
        }

        std::set<std::string> parentColours;
        add_all_parents( parentColours, rules.colourToBag.at( colourOfInterest ) );

        std::cout << "[Part 1]\n";
        std::cout << colourOfInterest << " parents: " << parentColours.size() << '\n';
        print( parentColours, '\n' );
    }

    {
        const auto lines = split( input, '\n' );
        Rules rules;

        for ( const auto& line : lines )
        {
            parse_line( line, rules );
        }

        std::cout << "\n[Part 2]" << '\n';
        std::cout << colourOfInterest << " contains "
                  << count_contained_bags( colourOfInterest, rules ) << " bags\n";
    }
}
