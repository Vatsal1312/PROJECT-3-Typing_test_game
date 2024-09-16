#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAX_LENGTH 256

// ANSI escape codes for colors
#define WHITE_BG "\033[48;2;255;255;255m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define ORANGE "\033[38;2;255;165;0m"
#define LIGHT_BLUE "\033[38;2;173;216;230m"
#define RESET "\033[0m"                    
#define SALMON_BG "\033[48;2;250;128;114m" 
#define RED_BG "\033[48;2;255;0;0m"        

// Sentences for different levels & facts
const char *easySentences[] = {
    "The quick brown fox jumps over the lazy dog.",
    "Hello world!",
    "I love programming.",
    "Dogs are very loyal.",
    "I enjoy reading books.",
    "The sky is blue.",
    "Have a great day.",
    "Coffee is life.",
    "Cats sleep a lot.",
    "It is raining outside.",
    "Learning is fun.",
    "You are doing well.",
    "Birds can fly high.",
    "Time flies so fast.",
    "I like playing games.",
    "I write code daily.",
    "Python is a cool language.",
    "Sunsets are beautiful.",
    "Happy moments last forever.",
    "Winter is coming.",
    "Spring brings flowers.",
    "I like pizza.",
    "The stars shine bright.",
    "Do you like chocolate?",
    "I enjoy hiking."};

const char *mediumSentences[] = {
    "Pack my box with five dozen liquor jugs.",
    "How razorback-jumping frogs can level six piqued gymnasts!",
    "A watched pot never boils.",
    "Honesty is the best policy.",
    "Never say never.",
    "The early bird catches the worm.",
    "Actions speak louder than words.",
    "Beauty is in the eye of the beholder.",
    "A picture is worth a thousand words.",
    "Better late than never.",
    "Barking dogs seldom bite.",
    "Blood is thicker than water.",
    "Practice makes perfect.",
    "Every cloud has a silver lining.",
    "An apple a day keeps the doctor away.",
    "A journey of a thousand miles begins with a single step.",
    "Fortune favors the bold.",
    "A rolling stone gathers no moss.",
    "All that glitters is not gold.",
    "Birds of a feather flock together.",
    "When in Rome, do as the Romans do.",
    "The pen is mightier than the sword.",
    "A friend in need is a friend indeed.",
    "Absence makes the heart grow fonder.",
    "Actions speak louder than words."};

const char *hardSentences[] = {
    "The five boxing wizards jump quickly.",
    "Glib jocks quiz nymph to vex dwarf.",
    "Jack quietly moved up front and seized the big ball of wax.",
    "My faxed joke won a pager in the cable TV quiz show.",
    "Vampire bats rely on hemoglobin as a key nutrient.",
    "Mr. Jock, TV quiz PhD, bags few lynx.",
    "Just keep examining every low bid quoted for zinc etchings.",
    "Heavy boxes perform quick waltzes and jigs.",
    "Crazy Fredrick bought many very exquisite opal jewels.",
    "The job requires extra pluck and zeal from every young wage earner.",
    "A wizard's job is to vex chumps quickly in fog.",
    "How razorback-jumping frogs can level six piqued gymnasts!",
    "We promptly judged antique ivory buckles for the next prize.",
    "Five or six big jet planes zoomed quickly by the new tower.",
    "Sixty zippers were quickly picked from the woven jute bag.",
    "The girl swiftly moved her big potted azaleas into the sunny atrium.",
    "Quartz glyph job vexed the pick.",
    "The job requires strong vocal skills, making it difficult.",
    "A big box of mixed juice waxes quickly.",
    "Fredrick owned quite a big jazzy gem shop in town.",
    "Jumping frogs expect quiet victories over vexed gymnasts.",
    "Zephyrs quickly hurtled big jagged rocks into the pond.",
    "Wizard Jack's job was to vex all foggy chumps daily.",
    "Dizzy Fredrick swiftly boxed many large items.",
    "Jack grabbed the fuzzy red gift box for his quiet friend."};

const char *typingFacts[] = {
    "The average typing speed is about 40 WPM.",
    "Touch typing can improve typing speed and accuracy.",
    "The QWERTY layout was designed to reduce typewriter jams.",
    "Typing without looking at the keyboard is called touch typing.",
    "The Dvorak Simplified Keyboard was designed for faster typing.",
    "Typing skills can improve cognitive functions and hand-eye coordination.",
    "The fastest typing speed recorded is over 200 WPM.",
    "Proper typing posture can help prevent repetitive strain injuries.",
    "Typing games can help improve your typing speed in a fun way.",
    "The first typewriter was invented in 1868 by Christopher Latham Sholes.",
    "A typing test can help you track your improvement over time.",
    "Typing accurately is just as important as typing quickly.",
    "The average person types about 40-60 words per minute.",
    "Good typing habits include proper hand positioning and taking breaks.",
    "Typing practice can help increase your productivity and efficiency.",
    "Voice recognition software is becoming more popular but typing remains essential.",
    "Typing tests are used in job applications to assess candidates' skills.",
    "Using keyboard shortcuts can significantly improve productivity.",
    "Typing without errors is key to achieving high typing speeds.",
    "Regular typing practice can lead to long-term improvement in speed and accuracy."};

// Function to display a random typing fact or shortcut
void displayTypingFact()
{
    int numFacts = sizeof(typingFacts) / sizeof(typingFacts[0]);
    printf(LIGHT_BLUE "\n\n\t\t\t\t Fact: %s\n" RESET, typingFacts[rand() % numFacts]);
}

// Function to get user input
void getInput(char *buffer, int size)
{
    printf("\n\t\t\t\t");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
}

// Function to choose a random sentence based on difficulty level
const char *chooseSentence(int level)
{
    switch (level)
    {
    case 1: // Easy level
        return easySentences[rand() % 25];
    case 2: // Medium level
        return mediumSentences[rand() % 25];
    case 3: // Hard level
        return hardSentences[rand() % 25];
    default:
        return easySentences[0];
    }
}

void displayComparison(const char *input, const char *sentence)
{
    size_t correctChars = 0;              // Counter for correct characters
    size_t totalChars = strlen(sentence); // Total characters in the correct sentence

    printf(GREEN "\nCorrect sentence:\n");
    printf("%s\n" RESET, sentence); // Print the correct sentence in green color

    printf("\nYour input with mistakes highlighted:\n");
    size_t inputLen = strlen(input);

    // Loop through each character in the user's input and the correct sentence
    for (size_t i = 0; i < totalChars; i++)
    {
        if (i < inputLen)
        {
            if (input[i] == sentence[i])
            {
                printf("%c", input[i]); // Correct character
                correctChars++;         // Increment the correct character count
            }
            else
            {
                printf(SALMON_BG"%c" RESET, input[i]); // Highlight mistake
            }
        }
        else
        {
            printf(SALMON_BG " " RESET); // Handle missing characters in the user's input
        }
    }

    // Calculate accuracy percentage
    float accuracy = ((float)correctChars / totalChars) * 100;
    printf(GREEN "\n\n\t\t\t\tAccuracy: %.2f%%\n" RESET, accuracy); // Print accuracy percentage
}

int main()
{
    char userInput[MAX_LENGTH];
    int level, continueGame = 1, changeLevel;
    time_t startTime, endTime;
    double timeTaken, easyTime = 0, mediumTime = 0, hardTime = 0;

    // Seed random number generator once
    srand(time(NULL));

    printf(YELLOW "\n\n\n\t\t\t\t\t\t\t\tTYPING TEST GAME\n" RESET);

    // Display a random typing fact or shortcut
    Sleep(2000); // Pause for 2 seconds
    displayTypingFact();

    Sleep(2000); // Pause for 2 seconds before starting the game loop

    // Ask the user to choose a difficulty level
    printf(RED "\n\n\t\t\t\tChoose a difficulty level!" RESET);
    printf(GREEN "\n\t\t\t\t\tPRESS :\n\t\t\t\t\t\t(1) for EASY\n\n\t\t\t\t\t\t(2) for MEDIUM\n\n\t\t\t\t\t\t(3) for DIFFICULT\n\n\t\t\t\t\t\t" RESET);

    do
    {
        printf(BLUE);
        scanf("%d", &level);
        printf(RESET);
        getchar(); // To consume the newline character left by scanf

        if (level < 1 || level > 3)
        {
            printf(RED "\nInvalid input! Please choose a valid level (1 for EASY, 2 for MEDIUM, 3 for HARD).\n" RESET);
        }

    } while (level < 1 || level > 3);

    while (continueGame)
    {
        // Choose a random sentence based on the level
        const char *sentence = chooseSentence(level);

        // Display the sentence in yellow
        printf(YELLOW "\t\tType the following sentence:\n\n" RESET);
        printf(ORANGE "\t\t\t\t%s\n" RESET, sentence);

        // Record start time
        startTime = clock();

        // Get user input in blue
        printf(BLUE);
        getInput(userInput, MAX_LENGTH);
        printf(RESET);

        // Record end time
        endTime = clock();

        // Calculate time taken in seconds
        timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

        // Compare the user input with the correct sentence
        if (strcmp(userInput, sentence) == 0)
        {
            printf(GREEN "\n\n\t\t\t\t\t\tCorrect! Time taken: %.2f seconds\n" RESET, timeTaken);

            // Compare time for the same level
            if (level == 1) // Easy level
            {
                if (easyTime > 0)
                {
                    if (timeTaken < easyTime)
                    {
                        printf(LIGHT_BLUE "\n\t\t\t\t\tGood job! You typed faster than before in the Easy level.\n" RESET);
                    }
                    else
                    {
                        printf(LIGHT_BLUE "\n\t\t\t\t\tYou can do better! Try to type faster next time in the Easy level.\n" RESET);
                    }
                }
                easyTime = timeTaken; // Store the new time for easy level
            }
            else if (level == 2) // Medium level
            {
                if (mediumTime > 0)
                {
                    if (timeTaken < mediumTime)
                    {
                        printf(LIGHT_BLUE "\n\t\t\t\t\tGood job! You typed faster than before in the Medium level.\n" RESET);
                    }
                    else
                    {
                        printf(LIGHT_BLUE "\n\t\t\t\t\tYou can do better! Try to type faster next time in the Medium level.\n" RESET);
                    }
                }
                mediumTime = timeTaken; // Store the new time for medium level
            }
            else if (level == 3) // Hard level
            {
                if (hardTime > 0)
                {
                    if (timeTaken < hardTime)
                    {
                        printf(LIGHT_BLUE "\n\t\t\t\t\tGood job! You typed faster than before in the Hard level.\n" RESET);
                    }
                    else
                    {
                        printf(LIGHT_BLUE "\n\t\t\t\t\tYou can do better! Try to type faster next time in the Hard level.\n" RESET);
                    }
                }
                hardTime = timeTaken; // Store the new time for hard level
            }
        }
        else
        {
            printf(RED "\n\n\t\t\t\t\tIncorrect! Check your mistakes below:\n" RESET);
            displayComparison(userInput, sentence);
        }

        // Ask if the user wants to continue or change the level
        do
        {
            printf(LIGHT_BLUE "\n\n\t\t\t\tDo you want to continue? (1 for Yes, 0 for No): " RESET);
            scanf("%d", &continueGame);
            getchar(); // Consume newline character left by scanf

            if (continueGame != 1 && continueGame != 0)
            {
                printf(RED "\nInvalid input! Please enter 1 for Yes or 0 for No.\n" RESET);
            }
        } while (continueGame != 1 && continueGame != 0);

        if (continueGame)
        {
            do
            {
                printf(LIGHT_BLUE "\n\t\t\t\tDo you want to change the level? (1 for Yes, 0 for No): " RESET);
                scanf("%d", &changeLevel);
                getchar(); // Consume newline character left by scanf

                if (changeLevel != 1 && changeLevel != 0)
                {
                    printf(RED "\nInvalid input! Please enter 1 for Yes or 0 for No.\n" RESET);
                }
            } while (changeLevel != 1 && changeLevel != 0);

            if (changeLevel == 1)
            {
                // Ask for the new level
                do
                {
                    printf(RED "\n\n\t\t\t\tChoose a new difficulty level!" RESET);
                    printf(GREEN "\n\t\t\t\t\tPRESS :\n\t\t\t\t\t\t(1) for EASY\n\n\t\t\t\t\t\t(2) for MEDIUM\n\n\t\t\t\t\t\t(3) for DIFFICULT\n\n\t\t\t\t\t\t" RESET);
                    printf(BLUE);
                    scanf("%d", &level);
                    printf(RESET);
                    getchar(); // To consume the newline character left by scanf

                    if (level < 1 || level > 3)
                    {
                        printf(RED "\nInvalid input! Please choose a valid level (1 for EASY, 2 for MEDIUM, 3 for HARD).\n" RESET);
                    }
                } while (level < 1 || level > 3);
            }
        }
    }

    printf(YELLOW "\n\n\t\t\t\t\t\tThank you for playing!\n" RESET);
    return 0;
}
