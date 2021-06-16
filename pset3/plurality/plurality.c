#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//The maximum of candidates is 9.
#define MAX 9

//We define our new structure: candidate, which takes the string of names and the number of votes as parameters.
typedef struct
{
    string name;
    int votes;
}
candidate;

//We declare the array of candidates.
candidate candidates[MAX];

// Then, the number of candidates.
int candidate_count;

// ... and our function prototypes.
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    //We check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    //This populates the array of candidates, given a certain condition.
    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int votes = 0; votes < candidate_count; votes++)
    {
        candidates[votes].name = argv[votes + 1];
        candidates[votes].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    //Here we display the winner of the election
    print_winner();
}

//Here we update the vote totals given a new vote.
bool vote(string name)
{

    //We create a "for loop" to count the candidates all through the maximum number.
    for (int i = 0; i < candidate_count; i++)
    {
        //We compare the strings. If they match,
        if (strcmp(candidates[i].name, name) == 0)
        {
            //We add +1 at the vote for a specific candidate.
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    int maxvotes = 0;

    // We create a "for loop" to find the number of votes
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes > maxvotes)
        {
            maxvotes = candidates[j].votes;
        }
    }
    // and then we iterate over the candidates to see who has the highest vote.
    for (int k = 0; k < candidate_count; k++)
    {
        if (candidates[k].votes == maxvotes)
        {
            // Finally, we print the candidates with the maximum number of votes.
            printf("%s\n", candidates[k].name);
        }
    }

    return;
}

