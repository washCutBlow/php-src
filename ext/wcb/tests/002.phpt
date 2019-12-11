--TEST--
wcb_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('wcb')) {
	echo 'skip';
}
?>
--FILE--
<?php 
$ret = wcb_test1();

var_dump($ret);
?>
--EXPECT--
The extension wcb is loaded and working!
NULL
