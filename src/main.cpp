#include <Arduino.h>
#include <Preferences.h>
#include <stdio.h>

// komentarz dla testu githuba

class User
{
public:
  String username;
  String password;
};

class Login
{
public:
  String platform;
  String username;
  String password;
};
// put function declarations here:

Preferences preferences;

User user1, user2;
String correct_data;
Login users[10];

void setup()
{
  // for (int i = 0; i < 10; i++)
  // {
  //   users[i].platform = "platforma";
  //   users[i].username = "uzytkownik";
  //   users[i].password = "haslo";
  //   // preferences.putBytes("klucz"+(i+97), &users[i], sizeof(users[i]));
  // }

  preferences.begin("users0", false);
  preferences.getBytes("klucz0", &users[0], sizeof(users[0]));
  preferences.end();
  preferences.begin("users1", false);
  preferences.getBytes("klucz1", &users[1], sizeof(users[1]));
  preferences.end();
  preferences.begin("users2", false);
  preferences.getBytes("klucz2", &users[2], sizeof(users[2]));
  preferences.end();
  preferences.begin("users3", false);
  preferences.getBytes("klucz3", &users[3], sizeof(users[3]));
  preferences.end();
  preferences.begin("users4", false);
  preferences.getBytes("klucz4", &users[4], sizeof(users[4]));
  preferences.end();
  preferences.begin("users5", false);
  preferences.getBytes("klucz5", &users[5], sizeof(users[5]));
  preferences.end();
  preferences.begin("users6", false);
  preferences.getBytes("klucz6", &users[6], sizeof(users[6]));
  preferences.end();
  preferences.begin("users7", false);
  preferences.getBytes("klucz7", &users[7], sizeof(users[7]));
  preferences.end();
  preferences.begin("users8", false);
  preferences.getBytes("klucz8", &users[8], sizeof(users[8]));
  preferences.end();
  preferences.begin("users9", false);
  preferences.getBytes("klucz9", &users[9], sizeof(users[9]));
  preferences.end();

  preferences.begin("user1", false);

  // Tworzenie obiektu MojaKlasa

  user1.username = "uzytkownik1";
  user1.password = "haslo1";

  // Zapisywanie obiektu do pamięci flash
  // preferences.putBytes("klucz", &user1, sizeof(user1));  //uważaj z tym
  preferences.getBytes("klucz", &user2, sizeof(user2));

  // Zamknięcie obszaru pamięci flash
  preferences.end();

  // put your setup code here, to run once:
  // delay(1000);

  correct_data = "Username: " + String(user2.username) + ", Password: " + String(user2.password);

  Serial.begin(115200);
  // Serial.println(String(users[1].platform) + " x" + String(users[1].username) + " x" + String(users[1].password));
  //  Serial.println("Odczytane wartości:");
  //  Serial.println("username: " + String(user2.username));
  //  Serial.println("password: " + String(user2.password));
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    String data = Serial.readStringUntil('\n');
    // Tutaj dodaj kod obsługi danych (np. sprawdzenie loginu i hasła)

    if (data == correct_data)
    {
      Serial.println("correct login data");
    }
    else if (data == "login_query")
    {
      // Serial.println("nie dziala");
      // Serial.println(String(users[1].platform) + " se" + String(users[1].username) + " x" + String(users[1].password));
      for (int i = 0; i < 10; i++)
      {
        // preferences.getBytes("klucz"+(i+97), &users[i], sizeof(users[i]));
        String pakiet = (String(users[i].platform) + " " + String(users[i].username) + " " + String(users[i].password));
        Serial.println(pakiet);
      }
    }
    else
    {
      //Serial.println(data);
      Serial.println("incorrect login data");
    }
    // Następnie możesz wysłać odpowiedź do komputera przez Serial
    // Serial.println(data);
    // delay(100);
  }
}

// put function definitions here:
