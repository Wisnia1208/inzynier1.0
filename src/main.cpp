#include <Arduino.h>
#include <Preferences.h>

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

Preferences preferences;

User user2;
String correct_data;
Login users[10];

void setup()
{
  preferences.begin("users00", false);
  preferences.getBytes("klucz00", &users[0], sizeof(users[0]));
  preferences.end();
  preferences.begin("users1", false);
  preferences.getBytes("klucz1", &users[1], sizeof(users[1]));
  preferences.end();
  preferences.begin("users22", false);
  preferences.getBytes("klucz22", &users[2], sizeof(users[2]));
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

  preferences.begin("user2", false);
  preferences.getBytes("klucz", &user2, sizeof(user2));
  preferences.end();

  correct_data = "Username: " + String(user2.username) + ", Password: " + String(user2.password);

  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    String data = Serial.readStringUntil('\n');
    if (data == correct_data)
    {
      Serial.println("correct login data");
    }
    else if (data == "login_query")
    {
      for (int i = 0; i < 10; i++)
      {
        String pakiet = ("ptfr:" + String(users[i].platform) + " usrn:" + String(users[i].username) + " pssw:" + String(users[i].password));
        Serial.println(pakiet);
      }
    }
    else if (data == "change_data_on_0")
    {
      users[0].platform = Serial.readStringUntil(':');
      users[0].username = Serial.readStringUntil(':');
      users[0].password = Serial.readStringUntil(':');
      preferences.begin("users00", false);
      preferences.putBytes("klucz00", &users[0], sizeof(users[0]));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "change_data_on_1")
    {
      users[1].platform = Serial.readStringUntil(':');
      users[1].username = Serial.readStringUntil(':');
      users[1].password = Serial.readStringUntil(':');
      preferences.begin("users1", false);
      preferences.putBytes("klucz1", &users[1], sizeof(users[1]));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "change_data_on_2")
    {
      users[2].platform = Serial.readStringUntil(':');
      users[2].username = Serial.readStringUntil(':');
      users[2].password = Serial.readStringUntil(':');
      preferences.begin("users22", false);
      preferences.putBytes("klucz22", &users[2], sizeof(users[2]));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "change_data_on_3")
    {
      users[3].platform = Serial.readStringUntil(':');
      users[3].username = Serial.readStringUntil(':');
      users[3].password = Serial.readStringUntil(':');
      preferences.begin("users3", false);
      preferences.putBytes("klucz3", &users[3], sizeof(users[3]));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "change_data_on_4")
    {
      users[4].platform = Serial.readStringUntil(':');
      users[4].username = Serial.readStringUntil(':');
      users[4].password = Serial.readStringUntil(':');
      preferences.begin("users4", false);
      preferences.putBytes("klucz4", &users[4], sizeof(users[4]));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "change_data_on_5")
    {
      users[5].platform = Serial.readStringUntil(':');
      users[5].username = Serial.readStringUntil(':');
      users[5].password = Serial.readStringUntil(':');
      preferences.begin("users5", false);
      preferences.putBytes("klucz5", &users[5], sizeof(users[5]));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "change_data_on_6")
    {
      users[6].platform = Serial.readStringUntil(':');
      users[6].username = Serial.readStringUntil(':');
      users[6].password = Serial.readStringUntil(':');
      preferences.begin("users6", false);
      preferences.putBytes("klucz6", &users[6], sizeof(users[6]));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "change_data_on_7")
    {
      users[7].platform = Serial.readStringUntil(':');
      users[7].username = Serial.readStringUntil(':');
      users[7].password = Serial.readStringUntil(':');
      preferences.begin("users7", false);
      preferences.putBytes("klucz7", &users[7], sizeof(users[7]));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "change_data_on_8")
    {
      users[8].platform = Serial.readStringUntil(':');
      users[8].username = Serial.readStringUntil(':');
      users[8].password = Serial.readStringUntil(':');
      preferences.begin("users8", false);
      preferences.putBytes("klucz8", &users[8], sizeof(users[8]));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "change_data_on_9")
    {
      users[9].platform = Serial.readStringUntil(':');
      users[9].username = Serial.readStringUntil(':');
      users[9].password = Serial.readStringUntil(':');
      preferences.begin("users9", false);
      preferences.putBytes("klucz9", &users[9], sizeof(users[9]));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "change_login")
    {
      user2.username = Serial.readStringUntil(':');
      user2.password = Serial.readStringUntil(':');
      correct_data = "Username: " + String(user2.username) + ", Password: " + String(user2.password);
      preferences.begin("user2", false);
      preferences.putBytes("klucz", &user2, sizeof(user2));
      preferences.end();
      preferences.begin("user2", false);
      preferences.getBytes("klucz", &user2, sizeof(user2));
      preferences.end();
      Serial.println("done");
    }
    else if (data == "emergency_reset")
    {
      user2.username = "uzytkownik1";
      user2.password = "haslo1";
      preferences.begin("user2", false);
      preferences.putBytes("klucz", &user2, sizeof(user2));
      preferences.end();
      correct_data = "Username: " + String(user2.username) + ", Password: " + String(user2.password);

      for (int i = 0; i < 10; i++)
      {
        users[i].platform = "platforma";
        users[i].username = "uzytkownik";
        users[i].password = "haslo";
        preferences.putBytes("klucz" + (i + 97), &users[i], sizeof(users[i]));
      }

      preferences.begin("users00", false);
      preferences.putBytes("klucz00", &users[0], sizeof(users[0]));
      preferences.end();
      preferences.begin("users1", false);
      preferences.putBytes("klucz1", &users[1], sizeof(users[1]));
      preferences.end();
      preferences.begin("users22", false);
      preferences.putBytes("klucz22", &users[2], sizeof(users[2]));
      preferences.end();
      preferences.begin("users3", false);
      preferences.putBytes("klucz3", &users[3], sizeof(users[3]));
      preferences.end();
      preferences.begin("users4", false);
      preferences.putBytes("klucz4", &users[4], sizeof(users[4]));
      preferences.end();
      preferences.begin("users5", false);
      preferences.putBytes("klucz5", &users[5], sizeof(users[5]));
      preferences.end();
      preferences.begin("users6", false);
      preferences.putBytes("klucz6", &users[6], sizeof(users[6]));
      preferences.end();
      preferences.begin("users7", false);
      preferences.putBytes("klucz7", &users[7], sizeof(users[7]));
      preferences.end();
      preferences.begin("users8", false);
      preferences.putBytes("klucz8", &users[8], sizeof(users[8]));
      preferences.end();
      preferences.begin("users9", false);
      preferences.putBytes("klucz9", &users[9], sizeof(users[9]));
      preferences.end();
    }
    else
    {
      Serial.println("incorrect login data");
    }
  }
}
