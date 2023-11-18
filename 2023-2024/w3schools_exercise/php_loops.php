<?php
$i = 1;
while ($i < 6){
    echo $i;
    $i++;
}

do{
    echo $i;
    $i++;
}while($i <6);

for ($i = 0; $i < 10; $i++){
    echo $i;
}

$colors = array("red", "green", "blue", "yellow");

foreach ($colors as $x) {
    echo $x;
}

/*
 * output
 * 1234560123456789redgreenblueyellow
 */