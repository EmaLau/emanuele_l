<?php
include'footer.php';

echo readfile("webdict.txt");


$myfile = fopen("webdict.txt", "r");

while(!feof($myfile)) {
    echo fgetc($myfile);
}
setcookie("username", "John", time() + (86400 * 30), "/");

session_start();
$_SESSION["favcolor"]= "green";
echo $_SESSION["favcolor"];

/*
 * output
 *
Warning: include(footer.php): Failed to open stream: No such file or directory in /Users/emalau/Desktop/emanuele_l/2023-2024/w3schools_exercise/php_advanced.php on line 2

Warning: include(): Failed opening 'footer.php' for inclusion (include_path='.:/opt/homebrew/Cellar/php/8.2.10/share/php/pear') in /Users/emalau/Desktop/emanuele_l/2023-2024/w3schools_exercise/php_advanced.php on line 2

Warning: readfile(webdict.txt): Failed to open stream: No such file or directory in /Users/emalau/Desktop/emanuele_l/2023-2024/w3schools_exercise/php_advanced.php on line 4

Warning: fopen(webdict.txt): Failed to open stream: No such file or directory in /Users/emalau/Desktop/emanuele_l/2023-2024/w3schools_exercise/php_advanced.php on line 7

Fatal error: Uncaught TypeError: feof(): Argument #1 ($stream) must be of type resource, bool given in /Users/emalau/Desktop/emanuele_l/2023-2024/w3schools_exercise/php_advanced.php:9 Stack trace: #0 /Users/emalau/Desktop/emanuele_l/2023-2024/w3schools_exercise/php_advanced.php(9): feof(false) #1 {main} thrown in /Users/emalau/Desktop/emanuele_l/2023-2024/w3schools_exercise/php_advanced.php on line 9
 */