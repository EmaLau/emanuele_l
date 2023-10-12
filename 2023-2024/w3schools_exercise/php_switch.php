<?php
$color= "red";
switch ($color){
    case "red";
    echo "Hello";
    break;
    case "green";
    echo"Welcome";
    break;
}
$color1 = "blue";
switch ($color1) {
    case "red":
        echo "Hello";
        break;
    case "green":
        echo "Welcome";
        break;
    default:
        echo "Neither";
}

/*
 * output
 * HelloNeither
 */