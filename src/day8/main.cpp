#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <iostream>

const std::string sample_part1_input = R"(nop +0
acc +1
jmp +4
acc +3
jmp -3
acc -99
acc +1
jmp -4
acc +6)";

struct ProgramState
{
    int accumulator = 0;
    int line_number = 0;
    std::unordered_set<int> executed_lines;
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

std::vector<std::pair<std::string, int>> read_input( const std::string& filename )
{
    std::ifstream input_file( filename );
    std::string line;
    std::vector<std::pair<std::string, int>> inputs;
    inputs.reserve( 5192 );

    while ( std::getline( input_file, line ) )
    {
        const auto split_line = split( line, ' ' );
        inputs.emplace_back( split_line.at(0), std::stoi( split_line.at(1) ) );
    }

    return inputs;
}

void execute_line( const std::pair<std::string, int>& line, ProgramState& program_state )
{
    if ( line.first == "nop" )
    {
        program_state.executed_lines.insert( program_state.line_number );
        program_state.line_number++;
    }
    else if ( line.first == "acc" )
    {
        program_state.accumulator += line.second;

        program_state.executed_lines.insert( program_state.line_number );
        program_state.line_number++;
    }
    else if ( line.first == "jmp" )
    {
        program_state.executed_lines.insert( program_state.line_number );
        program_state.line_number += line.second;
    }
    else
    {
        throw std::runtime_error( "Unhandled instruction: " + line.first );
    }
}

void run_until_infinite_loop_found( const std::vector<std::pair<std::string, int>>& input, ProgramState& program_state )
{
    bool line_previously_executed = false;

    while ( !line_previously_executed )
    {
        execute_line( input.at( program_state.line_number ), program_state );

        if ( program_state.executed_lines.find( program_state.line_number ) !=
            program_state.executed_lines.end() )
        {
            line_previously_executed = true;
        }
    }
}

int main()
{
    const auto input = read_input( "day8_input.txt" );
    ProgramState program_state;

    run_until_infinite_loop_found( input, program_state );

    std::cout << "[PART 1]\nAccumulator = " << program_state.accumulator << '\n';
}
