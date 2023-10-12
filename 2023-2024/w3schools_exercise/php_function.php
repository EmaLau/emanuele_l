<?php

function myFunction(){
    echo "Hello World!";
}

myFunction();
function myFunction1($fname, $lname) {
    echo $fname ;
}

myFunction1("ciao", "ciao2");

function myFunction2($fname1, $lname1){
    return $lname1;
}

myFunction2("ciao3", "ciao4");

/*
 * output
 * Hello World!ciao
 */