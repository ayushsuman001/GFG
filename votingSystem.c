#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 50
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

// Candidate structure
struct Candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

// Voter structure
struct Voter {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int voterID;
    int voted;
};

// Function prototypes
void addCandidates(struct Candidate candidates[MAX_CANDIDATES], int *numCandidates);
void addVoters(struct Voter voters[MAX_VOTERS], int *numVoters);
void vote(struct Candidate candidates[MAX_CANDIDATES], int numCandidates, struct Voter voters[MAX_VOTERS], int numVoters);
void displayResults(struct Candidate candidates[MAX_CANDIDATES], int numCandidates);

int main() {
    struct Candidate candidates[MAX_CANDIDATES];
    int numCandidates = 0;

    struct Voter voters[MAX_VOTERS];
    int numVoters = 0,ch;

    printf("\n-------------------------------------\n");
    printf("\nVoting System\n");
    printf("\n-------------------------------------\n");

    do {
        printf("\nMain Menu:\n\n");
        printf("1. Add candidates\n");
        printf("2. Add voters\n");
        printf("3. Caste a Vote\n");
        printf("4. Election results\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                addCandidates(candidates, &numCandidates);
                break;
            case 2:
                addVoters(voters, &numVoters);
                break;
            case 3:
                vote(candidates, numCandidates, voters, numVoters);
                break;
            case 4:
                displayResults(candidates, numCandidates);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

    } while (ch != 5);

    return 0;
}

void addCandidates(struct Candidate candidates[MAX_CANDIDATES], int *numCandidates) {
    if (*numCandidates >= MAX_CANDIDATES) {
        printf("Maximum candidates limit reached!\n");
        return;
    }

    printf("Enter the name of candidate %d: ", *numCandidates + 1);
    scanf("%s", candidates[*numCandidates].name);
    candidates[*numCandidates].votes = 0;

    (*numCandidates)++;
    printf("Candidate added successfully!\n");
}

void addVoters(struct Voter voters[MAX_VOTERS], int *numVoters) {
    if (*numVoters >= MAX_VOTERS) {
        printf("Maximum voters limit reached!\n");
        return;
    }

    printf("Enter the name of voter %d: ", *numVoters + 1);
    scanf("%s", voters[*numVoters].name);

    printf("Enter the address of voter %d: ", *numVoters + 1);
    scanf(" %[^\n]", voters[*numVoters].address);

    printf("Enter the voter ID of voter %d: ", *numVoters + 1);
    scanf("%d", &voters[*numVoters].voterID);

    voters[*numVoters].voted = 0;

    (*numVoters)++;
    printf("Voter added successfully!\n");
}

void vote(struct Candidate candidates[MAX_CANDIDATES], int numCandidates, struct Voter voters[MAX_VOTERS], int numVoters) {
    char voterName[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter your name to cast your vote: ");
    scanf("%s", voterName);

    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].voted == 0) {
                printf("Candidates standing for the post:\n");
                for (int j = 0; j < numCandidates; j++) {
                    printf("%d. %s\n", j + 1, candidates[j].name);
                }
                printf("%d. NOTA\n", numCandidates + 1);

                int choice;
                printf("Enter the number corresponding to the candidate you want to vote for: ");
                scanf("%d", &choice);

                if (choice >= 1 && choice <= numCandidates) {
                    candidates[choice - 1].votes++;
                    printf("Vote casted successfully!\n");
                    voters[i].voted = 1;
                } else if (choice == numCandidates + 1) {
                    printf("You have chosen NOTA (None of the above).\n");
                    voters[i].voted = 1;
                } else {
                    printf("Invalid choice!\n");
                }
            } else {
                printf("You have already casted your vote.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Voter not found. Please register as a voter first.\n");
    }
}

void displayResults(struct Candidate candidates[MAX_CANDIDATES], int numCandidates) {
    int maxVotes = -1;
    int tie = 0;

    printf("Candidates with their votes:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            tie = 0;
        } else if (candidates[i].votes == maxVotes) {
            tie = 1;
        }
    }

    if (!tie) {
        printf("The winner is:\n");
        for (int i = 0; i < numCandidates; i++) {
            if (candidates[i].votes == maxVotes) {
                printf("%s\n", candidates[i].name);
            }
        }
    } else {
        printf("It's a tie! All the following candidates are declared as winners:\n");
        for (int i = 0; i < numCandidates; i++) {
            if (candidates[i].votes == maxVotes) {
                printf("%s\n", candidates[i].name);
            }
        }
    }
}
