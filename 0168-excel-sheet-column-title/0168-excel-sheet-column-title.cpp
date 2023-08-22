class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            // Convert the column number to 0-based index
            columnNumber--;

            // Calculate the remainder to determine the character
            char character = 'A' + (columnNumber % 26);

            // Append the character to the result
            result = character + result;

            // Update the column number for the next iteration
            columnNumber /= 26;
        }

        return result;
    }
};