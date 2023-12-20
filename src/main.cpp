#include <Arduino.h>
#include <Preferences.h>

class User
{
public:
  String username;
  String password;
};
// put function declarations here:

Preferences preferences;

User user1, user2;
String correct_data;

void setup()
{
  Serial.begin(115200);

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

  Serial.println("Odczytane wartości:");
  Serial.println("username: " + String(user2.username));
  Serial.println("password: " + String(user2.password));
  correct_data = "Username: " + String(user2.username) + ", Password: " + String(user2.password);
  // Serial.println("Hello world");
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
    else
    {
      Serial.println("incorrect login data");
    }
    // Następnie możesz wysłać odpowiedź do komputera przez Serial
    // Serial.println(data);
    //delay(100);
  }
}

// put function definitions here:
