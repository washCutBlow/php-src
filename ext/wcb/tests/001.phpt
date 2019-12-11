--TEST--
Check if wcb is loaded
--SKIPIF--
<?php
if (!extension_loaded('wcb')) {
	echo 'skip';
}
?>
--FILE--
<?php 
echo 'The extension "wcb" is available';
?>
--EXPECT--
The extension "wcb" is available
