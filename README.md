# ☑️ Statistics library
This was the 3rd evaluation of my month of training which was done after two week into the process. This was most definetely my most impressive piece of work in C++ thus far and what I'm most proud of. I've properly documented code, clean architecture and i use complicated C++ concepts to realize the idea.  It's a pretty basic UI and the magic lies in the backend, the logic in the source code. This code is a statistics library which let's you analyze and get key numbers on your data.

## ❇️Features
- **Templates**: Templates allow for different datatypes to be assigned our vectors, primarily float, double and int as other datatypes wouldn't allow for a lot of the calculations the program does.
- **Fstream**: We use this to read the CSV file and actually extract data, I used a pretty difficult approach which was the only one I could think of to allow the user to only work with one of the rows as the user desires.
- **Data analysis**: I have a plethora of options to look at data, the program can calculate the mean, mode, variance, median, et cetera. 
- **Dynamic availability**: As with most of my programs it's a program that can adapt to the size of your CSV file and is perfectly scalable without you having to make any changes apart from the file name in the code.

#### This project was made entirely in C++ with these following libraries: iostream, vector, algorithm, map, fstream, cmath, string

## 🤔The Process 

I realized at the very beginning I would make a simple UI and have all the calculations be done in their own functions, however something I didn't realize was that the start was suprisingly easy. The difficult part was optimizing the code and setting up more difficult calculations, like with the median function I need to pass the vector as an argument by value and not reference so I could sort it and go to the middle. I also realized the process of allowing the user to select a row was super difficult, mainly because I didn't know any easy way to do it. So my solution was improvised and a little rough but fully functional.

## 📚My takeaways

My first time using templates properly and it was very educational. I also developed a deeper understanding of syntax and concepts as passing my reference, const or not, et cetera.

I also learnt something which I kinda new, I just realized it, a simple architecture is key for a project with a timelimit. Make a super basic working prototype and then improve it.


## 🚀Running the project 

1. Install the StatisticsLibrary.cpp file alongside C++ on your code editor.
2. Open the cpp file and change the already placed csv file name to a file of your choice.
3. Run your code.

## 🍿Video
https://github.com/user-attachments/assets/92d1a36f-95c2-4800-bbe5-512cf307c7c9
