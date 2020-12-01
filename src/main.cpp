#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct TwoInts
{
    int first;
    int second;
};

struct ThreeInts
{
    int first;
    int second;
    int third;
};

template<typename T>
TwoInts FindSummingPair( const T& inputs, const int target )
{
    for ( const auto val1 : inputs )
    {
        const auto iter =
            std::find_if( inputs.begin(), inputs.end(), [val1, target]( const int val2 ) {
                return val1 + val2 == target;
            } );

        if ( iter != inputs.end() )
        {
            return { val1, *iter };
        }
    }

    return { 0, 0 };
}

template<typename T>
ThreeInts FindSummingTriplet( const T& inputs, const int target )
{
    for ( const auto val1 : inputs )
    {
        for ( const auto val2 : inputs )
        {
            const auto iter =
                std::find_if( inputs.begin(), inputs.end(), [val1, val2, target]( const int val3 ) {
                    return val1 + val2 + val3 == target;
                } );

            if ( iter != inputs.end() )
            {
                return { val1, val2, *iter };
            }
        }
    }

    return { 0, 0, 0 };
}

template<typename... T>
void PrintSumAndProduct( const T... vals )
{
    std::cout << "Sum: " << ( vals + ... ) << '\n';
    std::cout << "Product: " << ( vals * ... ) << '\n';
}

std::vector<int> GetInputs( const std::string& filename )
{
    std::ifstream inputFile( filename );
    std::string line;
    std::vector<int> inputs;
    inputs.reserve( 200 );

    while ( std::getline( inputFile, line ) )
    {
        inputs.push_back( std::stoi( line ) );
    }

    return inputs;
}

int main()
{
    const auto inputs = GetInputs( "day1_input.txt" );
    const auto target = 2020;

    const auto sumPair = FindSummingPair( inputs, target );
    PrintSumAndProduct( sumPair.first, sumPair.second );

    const auto sumTriplet = FindSummingTriplet( inputs, target );
    PrintSumAndProduct( sumTriplet.first, sumTriplet.second, sumTriplet.third );

    return 0;
}
