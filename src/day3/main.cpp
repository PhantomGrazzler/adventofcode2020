#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

const std::string input = R"(.#..............##....#.#.####.
##..........#.....##...........
.......#....##...........#.#...
.........#.#...#..........#....
.........#..#................##
..#...#..#..#...........#......
...................#...##..##..
........#.....##...#.#.#...#...
#..#.##......#.#..#..........#.
......#.#...#.#...#........##.#
.....#.####........#...........
...###..#............#.........
.....#.......##......#...#.....
#......##......................
......#..............#.........
..##...#....###.##.............
#...#..........#.#.........#...
...........#........#...#......
.....##.........#......#..#....
#..............#....#.....#....
.#......#....#...#............#
.####..........##..#.#.........
....#...#......................
....................#....#.#...
..........###.#...............#
.#...........#...##............
.#.#..#.....#...#....#.......#.
.##........#..#....#...........
.........#.....#......###......
..............#..#.......#.....
........#..#.#...........#..#..
#.........#......#.....##.#.#..
........#.#.#....#.............
........#........#.#.##........
#......#.#..........#..#.......
..#....#...##......###..#..#...
............#..#.#.........#...
....#.#...........#..........##
.......#.#.#..#......#...#.....
..#.........##.#.........#...#.
......#....#.#....#........#.#.
.#....###....#..............#..
.#....#.......#....#..#.....#..
.....#.....#...................
..#.....#......#......#........
......##.##...#...#...#...#.##.
##...#....#...#..#...#...#.....
..#.....#...#...##.##...#......
.....#.............##...#......
.....................#.##..#...
#...#....#....#........#.....#.
..#...#.........#...#..#.....#.
#.#......#...................#.
..#...........##...............
..#....#........#..#...........
...........#...................
.............###......#....#...
...........#...#....#..#....#..
.....##............#.#.......#.
.....#..#....#...#....#........
...............##........#.#...
.........#...#.#....#.......#..
#..#.......#.......#...#.......
..#...........................#
......#.......#..#......#......
.#.......#..................##.
..#.........#..#.##.#....#...##
...#..#....#...#....#.#........
.#...#........##..#..#.......#.
.....#........#....#....#..#...
............#...........#......
..###.......#..#....#......#...
.....#...#.......#..#..........
..#........##.#....##..........
#....#.............#..##......#
....#.................##.......
...#.......#........#....##.#.#
##..##..#.....#.....#..........
...#...............#....#..#...
.#...##....#....#.....#....##..
...#.....#......#......#.......
#.....#.......##.....#..#....##
.....#.#...##.#......##....#.#.
..........#....#.#...#.........
.#..##...#.....................
...........##..#...#....#......
...#......#........#.......#...
.#......#..#........#.....#..#.
.......#........##..#.##....#..
.##..........#..#...#.....#....
.....##...............#.#......
..##.....#..#......#..##.#.#...
....#......#.##...........#....
#.#..#.......#......#.#........
...#.#..#....#............#..#.
...#..........###....#....#...#
........##...#.......#..#....#.
..#...#.....#..#........##.....
...#..#.##.#.#.##..............
.......#...#.........#.....#..#
..#.....#.#..........#..#......
......#..........#......#.....#
.#...........#........#......##
..##............#......#...#..#
#..................#...........
#....#..#.........#........#..#
..#.#....###..#...#...##...##..
...#....#..#.....#.............
.#........##.##...#....#...#...
.........#.......##.#.....##...
#.#.....##...#........#...#...#
.....#.#.##...#.....#.##..#....
........#...##...#...#.#..#..#.
.##....#.##...#.......#........
...#..#................#..#....
....#.......#......#...#.##....
#......###..#...#......#.......
..#...#...##...........##......
.......#...#..##....##......#..
....#.#.............#.#...##..#
..........#........#...#......#
............#.#.#....###.......
#..#...#.#.####...#..#...#.....
.##.......#.##...#.............
#..#...........#.#.##.......#..
...#..#.#...#...###..#.#..#.#..
..#...#.....#..#....#....#.....
.........##.......#............
.........##.##......###........
.............#.#....#..#.....#.
...#....#.#.......#......##....
............#..................
....##...#..........#...#..#...
#..#....#.....#.......#.##.#..#
.....#.........##.............#
#.....#.#...#............##..##
..............#....#.....#.....
.#....###..#.#.....###.#..#....
.....#....##...#....#......#...
..........#...#....#...........
............#....#..#.........#
..##.....#.#...#.......#...#...
...#...#..#......##...#.....##.
......#.##............##.#....#
....#......#...##.....#.....###
.#.###...............#...#.#...
..#....................##...#..
.......#.....##...........#....
#.........#....#....#....#....#
..#.#..##.#.#..................
.....#.......#................#
...........#.......#........#..
#...#.........#.#.....#.....#..
..........#..#...........#.....
#..#.##..##..#.#.##.........#..
#..#..#....##..#.........#.....
#.#.......................#.#..
.##......#.#...#......#....#...
..#.#................#..##.....
.......#..................#...#
.....#.........##.#....#.......
#..........#..#.#..........#..#
..#..#.....#.........#...#.....
..............#.....#..#...#.##
...............................
...#............##......#.....#
.......#..#.............#.#....
...........#..........#........
...#.####..#......#...#....#...
##......#.##.....#.............
....#.........#...#...........#
...#........#.......#.#..#.#.#.
..#.......#.........#....#.....
................#.#.#.##...#..#
#.##...#...#..#.....#.....#..#.
...............#...........#...
.....##.#...............##...#.
.#..##.##......................
.......#.........#..#..#.......
...#......#..................#.
...#.#..#....#....#............
...........#...#..#....##......
.....#...#..#.#....#....#....#.
.......#...#...#.#.#...........
....#......#......#...##..#....
##...#.#.....#..#.##...........
#.#..#.....#..#................
...#..#.#......#.#...........##
##....#...#.....###..#...#....#
...#.....#.#.#......##...#...#.
............#.......#..........
....#..........###.......#.....
.................##..##....#...
...........#........##..#......
...#.#...#.....#........#...#..
#...#.#......#.#...........#...
..#..........#....#..........#.
..#................#...........
#...#.#....#.#.......#.........
.#...........##..#....#....#..#
.##........#.....#...#..#....#.
......#......#...#.............
.......#..#...#.##....#..#.#...
.......#......#....#....#.#.#..
..........##.....#....##.#.....
.........##..#...#.....#..#....
...#....#..........#..#...#..#.
.......#.....##.#..#.....#...#.
#...#......#......#...#........
#..#....#.#......#......#......
.......#.##....................
...##...#.....#......##......#.
.#...................###.......
....#........###...#........#..
...#............#.....#..#.....
..................#......#....#
..##......#..##..##......#.#...
........##....##.......#...#...
.#.#....#.....#.....#....#....#
...##.#.............#....##....
.........#.....#...#......#....
..#.....#............#....##...
..##.....#.....##.##...........
#....#.#.......#..#......#.....
##.......#.....#.....####....#.
##...#.......#...#.....#.......
#.....#..##.##...##..#.....#..#
..........#......#..#.#........
..##.#......#..............#...
.#...#..........#.......#....#.
..#....##...#...........#....#.
..#.........#..#......#......#.
.##....#......#.#.........#..##
.......#...#....##............#
.##.................#.#........
...#.#...#..#..#.....#.#.......
.#.#.......#...................
..#..#.....#......#.....##..##.
.#........#.##......#..........
....##...#............#.#....#.
.......#.#..#....##.#....#....#
......####...#..#.....#........
..........#..#.........#.#..#.#
..........##.........#.##......
.##..#.#.....#.....#....#......
............#..#...............
.....##.........#...#...##...##
........#.##.#...#.....#....#.#
#......##.#.##..........##.....
#..#..#........#.........#..#..
...............#.#..##.........
.#.......##.#..#....#...#....##
.#..##.....##......#....#...#.#
........#...#.........#.....#.#
...........#............#...#..
................#...........#..
..............##........#....#.
..........#.....##.....#..#....
#......#....###..#..#..........
.....#.#.....##....#.#.......#.
...#...#...............#.#.....
.............#.......#.........
.....#.....#..#......#.....#...
.........#.................#.##
.#.....#.##..#.................
..#......#.......#.....#...#..#
..#..#.#.#...#.......#.##......
..........#..#.........#.......
.#..........#...#....#..#...##.
.#.#.#.###.....#...#.#.#.......
....##............#............
.#.#.............#..#......#.#.
.#.#..........##..#.....#..#.#.
...........#.##..#...#.#.....#.
...........#..#....#...........
..#................#.#...#....#
...............##........##....
....#.............#........#...
...#......#.#.#........#.......
#..............#..##.#..##.....
.#.#.###................##.....
.............#..#.........#....
.......##..#............#...#..
...#...#...........#.....#.....
........#......#.#.#......#..#.
#.##.......#......#..#..#.#....
...#........#...........#...#..
..#...........#.........#......
.............#....#....#.......
....#.........#........#......#
..#............##..#.........#.
.#...#...#..#...#........#..#..
...#....##..............#......
...........#...#....#.#.##..###
..#....#......#.........#..#...
.......#...#...................
.#...#.#...................#...
.#.....##.#.......#.#.#...##..#
.....#..#.#.........#...#..##..
.#..#.##.#......#......#.#...#.
......#..#....##..#....##....##
#...#......##........##........
.#.........###................#
.................#..###..#.#...
..#.#........#..#........#...#.
#.#....#....#..#...#.#......#..
.#.#.............###.........#.
.....#...............##...#...#
..............#...#........#..#
...................#..#.......#
#......................#.....#.
...#.........#..##...#...#.##..
.....#..........#.........#....
.....#...#............#..#.....
.............#............#....
...#.........#.................
#...........#.#...............#
.....#...#.....#..#.##.......##
...#....#.#...........#........
.........................#.#...
.#..#...........#.#........#...
.............#.#.....#..#....#.
.....#...#.###...#..#........#.)";

struct Slope
{
    Slope( const int right, const int down )
        : right( right )
        , down( down )
    {}

    int right;
    int down;
};

struct Position
{
    std::size_t line = 0;
    std::size_t offset = 0;

    Position& operator+=( const Slope& slope )
    {
        line += slope.down;
        offset += slope.right;

        return *this;
    }
};

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

int count_trees_hit( const std::vector<std::string>& lines, const Slope& slope )
{
    Position currentPosition;
    const auto lineLength = lines.at( 0 ).size();
    int treesHit = 0;

    while ( currentPosition.line < lines.size() )
    {
        const auto& currentLine = lines.at( currentPosition.line );
        const auto character = currentLine.at( currentPosition.offset % lineLength );

        if ( character == '#' )
        {
            treesHit++;
        }

        currentPosition += slope;
    }

    return treesHit;
}

int main()
{
    const Slope slopePart1( 3, 1 );
    const auto lines = split( input, '\n' );

    std::cout << "[Part 1] Trees hit: " << count_trees_hit( lines, slopePart1 ) << '\n';

    const std::vector<Slope> slopes = { { 1, 1 }, { 3, 1 }, { 5, 1 }, { 7, 1 }, { 1, 2 } };
    int product = 1;

    for ( const auto& slope : slopes )
    {
        product *= count_trees_hit( lines, slope );
    }

    std::cout << "[Part 2] Product: " << product << '\n';

    return 0;
}
