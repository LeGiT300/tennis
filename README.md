This program implements a tennis scoreboard simulation with detailed scorekeeping and real-time updates for each point, game, and set. It uses the following structure and logic:

---

## **Key Features**
1. **Score Tracking**:
   - Points, games, and sets are tracked for each player (Team A and Team B).

2. **Rules Implementation**:
   - Tennis scoring rules are implemented:
     - A game is won if a player scores at least 4 points and leads by 2.
     - A set is won if a player wins at least 6 games and leads by 2.
     - A match is won if a player wins 3 sets.

3. **Dynamic Serving**:
   - The serving alternates between teams after each game.

4. **Real-Time Results**:
   - The scoreboard updates after every point, reflecting the current game and set scores.

---

## **Code Analysis**

1. **Variables**:
   - **`gamesA`, `gamesB`**: Games won by Team A and B in the current set.
   - **`pointsA`, `pointsB`**: Points scored by each team in the current game.
   - **`setsA`, `setsB`**: Total sets won by each team.
   - **`service`**: Keeps track of who serves (-1 for Team A, +1 for Team B).
   - **`counter`**: Tracks the number of completed sets.

2. **`results()` Function**:
   - Displays the current score, including points, games, and sets.
   - Handles special cases like "Deuce" and "Advantage."

3. **`pointsCalc()` Function**:
   - Maps the number of points to tennis scoring terminology (15, 30, 40).

4. **`main()` Function**:
   - Continuously reads input for which team scores (`A` or `B`).
   - Updates points, games, and sets based on the scoring rules.
   - Checks for game, set, and match winners after each point.
   - Calls `results()` to display the current state of the scoreboard.

---

## **Example Run**

### Input:
```
A A B A B B A A B B B A B
```

### Output:
```
============================
          SCOREBOARD
============================
Enter the team

A: TEAM A SCORES
B: TEAM B SCORES

Team A to serve
15 - Love
30 - Love
30 - 15
40 - 15
Game Team A
Team B to serve
Love - 15
Love - 30
...
```

---

## **Areas for Improvement**
1. **Input Handling**:
   - Current implementation reads characters without handling invalid inputs.
   - Add validation for inputs to ensure only 'A' or 'B' is accepted.

2. **Output Formatting**:
   - Avoid redundant `%d` placeholders for `results()` calls. Replace with proper formatting.

3. **End Game Logic**:
   - Automatically stop the game after determining the match winner to prevent further input.

4. **Refactor Code**:
   - Extract repetitive logic into reusable functions for better readability and maintainability.

5. **Edge Cases**:
   - Consider scenarios like tiebreaks for sets that reach 6-6.

6. **User Experience**:
   - Add clear instructions and better formatting for easier understanding.
