#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "HackMe_AP";
ESP8266WebServer server(80);

// ─── Level 1 — HTML Source Inspection ───
const char MAIN_PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html><head><title>ESP8266 CTF</title></head>
<body>
<h1>Welcome Challenger</h1>
<p>Find the hidden flags. Try <a href="/robots.txt">robots.txt</a> and the <a href="/login">login page</a>.</p>
<!-- FLAG{inspect_the_source} -->
</body></html>
)rawliteral";

// ─── Level 3 — Login Page (HTML form) ───
const char LOGIN_PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html><head><title>Admin Login</title></head>
<body>
<h2>Admin Login</h2>
<form method="POST" action="/login">
  <label>Username: <input type="text" name="username"></label><br><br>
  <label>Password: <input type="password" name="password"></label><br><br>
  <input type="submit" value="Login">
</form>
</body></html>
)rawliteral";

void handleRoot() {
  server.sendHeader("X-Hint", "admin:esp8266");
  server.send(200, "text/html", MAIN_PAGE);
}

void handleRobots() {
  server.send(200, "text/plain", "Disallow: /hidden-panel");
}

void handleHiddenPanel() {
  server.send(200, "text/plain", "FLAG{robots_reveal_paths}");
}

// Serve the login form (GET)
void handleLoginPage() {
  server.sendHeader("X-Hint", "admin:esp8266");
  server.send(200, "text/html", LOGIN_PAGE);
}

// Process login credentials (POST)
void handleLogin() {
  String user = server.arg("username");
  String pass = server.arg("password");
  if (user == "admin" && pass == "esp8266") {
    server.send(200, "text/plain", "FLAG{headers_leak_information}");
  } else {
    server.send(401, "text/plain", "Invalid login. Hint: check your request headers.");
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid);
  Serial.println("CTF Started");
  Serial.println(WiFi.softAPIP());

  server.on("/",            handleRoot);
  server.on("/robots.txt",  handleRobots);
  server.on("/hidden-panel",handleHiddenPanel);
  server.on("/login",  HTTP_GET,  handleLoginPage);   // serves the form
  server.on("/login",  HTTP_POST, handleLogin);        // processes credentials
  server.begin();
}

void loop() {
  server.handleClient();
}
