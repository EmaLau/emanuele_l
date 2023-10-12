<?php
$a =50;
$b = 10;

if ($a > $b){
    echo "Hello World!";
}

if($a != $b){
    echo"Hello World!2";
}

if($a == $b){
    echo "yes";
}else{
    echo "No";
}

if($a == $b){
    echo "1";
}elseif($a>$b){
    echo "2";
}else{
    echo "3";
}

/*
 * output
 * Hello World!Hello World!2No2
 */