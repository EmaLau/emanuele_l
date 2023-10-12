<?php

$fruits = array("Apple", "Banana", "Orange");
echo count($fruits);

echo $fruits[1];

$age = array("Peter"=>"35", "Ben"=>"37", "Joe"=>"43");

echo "Ben is " .$age['Ben'] . " years old.";

foreach ($age as $x => $y) {
    echo "Key=" .$x . ", Value=" .$y ;
}

sort($colors);
rsort($colors);

asort($age);

/*
 * output
 *3BananaBen is 37 years old.Key=Peter, Value=35Key=Ben, Value=37Key=Joe, Value=43
Fatal error: Uncaught TypeError: sort(): Argument #1 ($array) must be of type array, null given in /Users/emalau/Desktop/emanuele_l/2023-2024/w3schools_exercise/php_arrays.php:16 Stack trace: #0 /Users/emalau/Desktop/emanuele_l/2023-2024/w3schools_exercise/php_arrays.php(16): sort(NULL) #1 {main} thrown in /Users/emalau/Desktop/emanuele_l/2023-2024/w3schools_exercise/php_arrays.php on line 16
 */