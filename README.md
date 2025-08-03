# Cpp_t_contest
This repository contains C++ programs solving various real-world problems.
## Used Techniques

    Binary search (polygonal_pie.cpp)
    Graph theory (secret_santa.cpp)
    Dynamic programming (free_lunch.cpp, memory.cpp)
    Geometric algorithms (conference_room.cpp)
    Greedy approaches (maximizeSum.cpp, array_sum.cpp)
    String manipulation (trio.cpp)
    Mathematical computation (fractions.cpp, trueEven.cpp, meteo.cpp)
    Sequence construction (sequence.cpp)
    
How to compile and run the programs:
   ```
   # All programs are standard C++ and can be compiled with c++
   # Example
   c++ secret_santa.cpp
   ./secret_santa
   ```
Below is a detailed breakdown of each program 👇
## 1. mobile.cpp
Calculates final cost based on base price, actual (or average) usage and price usage exceeds included limit.

    Simple conditional arithmetic
    Practical Use:
    1. Telecom billing systems calculating data charges
    2. Cloud service pricing models with included/extra resource thresholds
    3. Utility billing systems (electricity/water) with base allowances
    
## 2. pie.cpp
Calculates how many times a number can be halved before every parting reached 1.

    Simple iterative algorithm with integer division
    Logarithmic reduction
    Practical Use:
    1. Tournament systems calculating elimination rounds to determine a winner which helps schedule match timing and court/dates allocations
    2. Computer network protocols determining optimal packet fragmentation thresholds when sending a 1000-byte file through a network with 300-byte maximum packets (the algorithm calculates it needs 4 transmissions: 300*3 + 100)  
    3. Game theory models for divide-and-choose fair division problems, where parties alternate being divider/chooser
    
## 3. ladder.cpp
Optimizes elevator movement in a multistory building to the minimal travel time for picking up/dropping off passengers at different floors.

    Compares multiple route options
    Considers time constraints
    Practical Use:
    1. High-rise emergency evacuation route optimization
    2. Warehouse logistics for optimal goods elevator scheduling
    3. Hospital bed elevator prioritization during peak hours
    
## 4. maximizeSum.cpp
Calculates maximum possible sum gain by replacing digits (up to allowed moves).

    Digit decomposition and greedy selection
    Prioritizes most significant digit changes
    Practical Use:
    1. RPG game mechanics for optimal skill point allocation to get biggest combat advantage
    2. Financial portfolio rebalancing to maximize digit-based security codes (a bank might rebalance account numbers from 371429 to 399999 when detecting fraud patterns, for example)
    3. Inventory management systems optimizing product combos assembling (a retailer could combine items priced at $47, $58, $63 into $99 "deal packages")
    
## 5. beautiful_digits.cpp
Counts numbers with all identical digits between given bounds.

    Generates numbers mathematically rather than checking each
    Handles large ranges efficiently
    Practical Use:
    1. Excluding "beautiful" numbers when lottery winning numbers creation to prevent fraud, encourage randomness and reduce cases where suspiciosly perfect numbers win
    2. Reject user-chosen PINs or passwords with identical digits forcing customers to use more complex combinations
    3. Prevents human reading errors caused by misreading repeated digits in aircraft component serial numbers, which could lead to fatal replacement mistakes during maintenance

## 6. odd_and_even_in_sequence.cpp
Finds mismatched odd/even positions in a sequence and identifies if the sequence can be fixed by swapping two elements just once.

    Checks element parity against index parity
    Finds at most two mismatched positions
    Practical Use:
    1. Validating barcode/QR code parity patterns
    2. Checking alternating shift schedules (day/night rotations)
    3. Verifying proper sequencing in manufacturing assembly lines
    
## 7. secret_santa.cpp
Validates and corrects Secret Santa gift assignments to ensure a single cycle where everyone gives/receives exactly one gift. Corrects invalid assignments by reassigning gifts when possible.

    Uses graph cycle detection to validate assignments
    Implements reassignment logic when someone gets two gifts or no gift
    Practical Use:
    1. Classroom assignment systems ensuring each student both tutors and gets tutored
    2. Shift scheduling where coworkers cover for each other in rotation
    3. Rotating oversight responsibilities among departments to prevent self-review and create mandatory cross-departmental verification chains

## 8. conference_room.cpp
Performs geometric transformations to align virtual space coordinates with physical room dimensions.

    Uses trigonometric transformations
    Handles scaling and rotation
    Practical Use:
    1. Digital twin implementations for smart office or smart home systems
    2. Hybrid Zoom/VR meetings with proper speaker placement relative to real room acoustics and correct avatar spacing to match physical distancing
    3. AR furniture placement apps ensuring proper scaling while virtual shopping at IKEA
    
## 9. free_lunch.cpp
Uses dynamic programming to find optimal coupon usage sequence for minimal spending over multiple days.

    2D DP table tracking cost and coupons
    Backtracks to find coupon usage days
    Practical Use:
    1. Meal plan optimization for budget-conscious families
    2. RPG character development with limited upgrade resources (when to use limited "doubleXP" coupon across multiple training sessions; upgrade permanent stat boots vs temporary buffs)
    3. Corporate cafeteria coupon allocation systems (a company tweaks the algorithm to ensure a) no employee gets >1 coupon/week; b) coupons distribute equally across departments)
    
## 10. polygonal_pie.cpp
Calculates a vertical line position that splits a polygon into two regions of equal area using binary search and shoelace formula.

    Implements Gauss's shoelace formula for area calculation
    Uses binary search to find the optimal dividing line
    Practical Use:
    1. Agricultural land fair division for inheritance or partnership dissolution
    2. Urban planning when splitting park areas or zoning districts
    3. CAD software for designing balanced mechanical parts

## 11. trueEven.cpp
Checks if all digits in a number are even digits (0, 2, 4, 6, 8).

    Digit extraction and modular arithmetic
    Practical Use:
    1. Data validation systems checking format compliance
    2. Financial systems validating account numbers with specific digit patterns
    3. Quality control systems verifying product codes meet criteria

## 12. trio.cpp
Counts occurrences of consecutive "abc" substring in a given string.

    String traversal and pattern matching
    Practical Use:
    1. DNA sequence analysis finding specific gene patterns
    2. Log file analysis detecting error patterns or event sequences
    3. Text processing systems identifying repeated phrases or codes

## 13. sequence.cpp
Constructs a sequence by inserting numbers left or right based on direction string.

    Dynamic array manipulation and insertion algorithms
    Practical Use:
    1. Undo/redo systems in text editors maintaining operation history
    2. Task scheduling systems organizing priorities based on dependencies
    3. GUI layout managers positioning elements based on user interactions

## 14. meteo.cpp
Calculates what day a missed diary entry should have been made based on current day and last entry.

    Date arithmetic and calendar calculations
    Practical Use:
    1. Scheduling systems calculating missed appointments or deadlines
    2. Payroll systems determining pay periods and missed timesheet dates
    3. Maintenance tracking systems identifying overdue service intervals

## 15. memory.cpp
Finds maximum mood sum on a staircase with ability to skip negative mood steps.

    Dynamic programming with skip optimization
    Practical Use:
    1. Investment portfolio optimization with limited loss-cutting opportunities
    2. Game path optimization with limited power-ups or skips available
    3. Resource allocation systems maximizing benefit while minimizing negative impacts

## 16. fractions.cpp
Adds two fractions and reduces the result to its simplest form.

    Greatest common divisor (GCD) and fraction arithmetic
    Practical Use:
    1. Financial calculators combining fractional percentages or rates
    2. Recipe scaling systems adding ingredient proportions
    3. Engineering calculations combining measurements in fractional units

## 17. array_sum.cpp
Determines if array sum can be calculated using minimum number of range clues with known values.

    Greedy interval covering algorithm
    Practical Use:
    1. Network monitoring systems determining minimum sensors needed for full coverage
    2. Security systems optimizing camera placement for complete area surveillance
    3. Quality assurance systems minimizing test cases while ensuring full code coverage
