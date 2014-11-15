const int numberOfQuestions = 4;
String questions[numberOfQuestions];
String name;
int currentQuestion;
int score;


int falseButtonState = 0;
int trueButtonState = 0;

const int trueButtonPin = 2;
const int falseButtonPin = 8;
const int pushed = HIGH;

void setup(){

  Serial.begin(9600);
  pinMode(trueButtonPin, INPUT);
  pinMode(falseButtonPin, INPUT);
  currentQuestion = 0;
  score = 0;
  
  //change these to your own questions and name
  name = "Brennan Morse";
  questions[0] = "Do I have an older Sibling??";
  questions[1] = "Do I play Clarenet?";
  questions[2] = "Is my middle name Scot?";
  questions[3] = "Have I ever sold over $1500 for an organazation?";
  
  Serial.println("Hello this is " + name + "'s about me quiz.");
}

void loop(){
  Serial.println("********************");
  Serial.println(questions[currentQuestion]);
  while(trueButtonState == 0 && falseButtonState == 0){
    trueButtonState = digitalRead(trueButtonPin);
    falseButtonState = digitalRead(falseButtonPin);
  }
  //is the button pushed?
  if(trueButtonState == pushed) {
    //if it is then print a message
    delay(500);
    switch(currentQuestion){
      case 0:
        Serial.println("Wrong Answer! I'm the oldest kid in my famaly");
        break;
      case 1:
        Serial.println("You're right! I play Bb clarenet in the school band.");
        score = score + 3;
        break;
      case 2:
        Serial.println("Wrong Answer, my middle name is Scott with two T's!");
        break;
      case 3:
        Serial.println("Right! I sold ~$1590 dolers worth of popcorn for the Boy Scouts of Amareca -BSA-!");
        score = score + 1.5;
        break;
    }
    delay(1000);
  }
  else if(falseButtonState == pushed){
    delay(500);
    switch(currentQuestion){
      case 0:
        Serial.println("You're right! I'm the oldest kid in my famaly.");
        score = score + 2;
        break;
      case 1:
        Serial.println("Wrong Answer,  I play Bb clarenet in the school band.");
        break;
      case 2:
        Serial.println("Right! my middle name is Scott with two T's.");
        score = score + 2;
        break;
      case 3:
        Serial.println("Nope! I sold ~$1590 dolers worth of popcorn for the Boy Scouts of Amareca -BSA-.");
        break;
    }
    delay(2000);
  }
  //reset buttons to zero
  trueButtonState = 0;
  falseButtonState = 0;
  //check to make sure we have another question
  if(currentQuestion < numberOfQuestions - 1){
    currentQuestion = currentQuestion + 1;
  }
  else{
    currentQuestion = 0;
    Serial.println("*********************");
    Serial.print("Your score was: ");
    Serial.print(score);
    Serial.print(" out of ");
    Serial.println(numberOfQuestions);
    Serial.println("*********************");
    score = 0;
    Serial.println("Hello this is " + name + "'s about me quiz.");
    delay(10000);
  }

}
