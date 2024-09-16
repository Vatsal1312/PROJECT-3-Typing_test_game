# Typing Test Game

### Situation
I wanted to apply my knowledge of C programming to create a typing test game that would help users improve their typing skills. The project aimed to incorporate various aspects of C, such as handling user input, managing strings, using randomization, and implementing time-based features.

### Task
My goal was to develop a typing test game that:
- Allows users to select a difficulty level (Easy, Medium, Hard).
- Presents a sentence for the user to type.
- Measures the time taken to type the sentence.
- Compares the user's input with the correct sentence and calculates the accuracy.
- Provides feedback on performance and highlights errors.
- Offers the option to continue playing or change the difficulty level.

### Action
I used the following techniques and libraries in C to accomplish the task:
- **ANSI Escape Codes**: For adding colors and background effects to make the game visually appealing.
- **String Handling**: Functions like `fgets`, `strlen`, and `strcmp` to manage and compare user input and sentences.
- **Randomization**: `rand()` to select random sentences and typing facts from predefined lists.
- **Time Measurement**: `clock()` to calculate the time taken for each typing test.
- **Control Flow**: Loops and conditionals to handle game flow, difficulty levels, and user choices.

### Result
The Typing Test Game successfully:
- Provides a user-friendly interface with color-coded feedback and typing facts.
- Accurately tracks and displays the time taken for typing tests and compares it with previous attempts.
- Allows users to continue playing, change difficulty levels, and improve their typing speed and accuracy.
- Highlights user mistakes and provides a detailed accuracy report on their typing performance. 

### Error
The code currently counts all characters as incorrect if a space is missed, even if all other characters are typed correctly. This issue occurs because the comparison logic does not properly handle missing spaces in the input.

