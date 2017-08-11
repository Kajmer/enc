<!DOCTYPE html>
<html>
<head>
</head>
<body>
<form action="" method="post">
    Your String is:           <input type="text" name="str" /><br>
	You better add some parameters! <br>
	Key (optional):   <input type="text" name="key" /><br>
	Iterations of encoding: <input type="number" name="iterations" value="1"/><br>
    <input type="submit" name="submit" value="Magic" />
</form>


<?php 
  	class encode {
		private $keyword; // change this
		private $str; //user-input
		private $encoded_str;
		private $iterations;

	public function __construct($str, $iterations = 1,
									$keyword = "hwGU4QqEUeyy61@bSqJv\$LJsY1XL9hAbD8qtY#2bqDfJWAMa9CP6bqTpfb8bBykPnQG8nHeNDytvr1J\$wa6@fkDwZPSw8CguMLimWpDJcdkPd5SgeuyVGCcew8AWZrn9WQfVSBcQD2LixaZ#cmtWCX93sHKGZBcW1a8ytAcQCqDuLQjw8ksMEF\$eCrBiS#Hefaj1RTrtqCeJQNTg85sg9@AgkJMJHV8MVkPaRxSydM2d4su#uZw8#3j2MpC8p2Xa\$kDJsGWDw5vM2G7hwTsdS\$A@N89mjvSqWWi8mJhPKZc1DQXMYxebx992CX2TjGXDhik36hegGZAiP8ciJXGv1yntEUx#KL7acduAPhRvWM4UM2Rxj2R#s6GTUQLmVUTEy4P5MWfyj9iR9dBVZp3CwXg73QMwj5m3nj585Vj836yxP@JbsASdByy3@vD9cE2KZnnuK92wRrtipLgZcKR6vknymDPAnBUF3fLH6vu5d@WukHMREg3vvStc2jENtNfq" // you better change this
									) {
			$this -> keyword = $keyword;
			$this -> str = $str;
			$this -> encoded_str = $str;
			$this -> iterations = $iterations;
		} 

	public function createWithKey($str, $keyword) {
		$this -> keyword = $keyword;
		$this -> str = $str;
		//echo "Created with key<br>"; //Debug
	}

	public function createWithoutKey($str) {
		$this -> str = $str;
		//echo "Created without key<br>"; //Debug
	}

	public function returnString() {
		//echo "Returning string...<br>"; //Debug
		return $this -> encoded_str; 
	}

	public function charToCode ($char) { // this for ASCII, create new func for utf?
		return ord($char);
	}

	public function codeToChar ($code = 0) { //ASCII
		if (($code == 0) || ($code < 32) || ($code > 126)) { // [32:127] ASCII
			echo "Wrong code in codeToChar()<br>"; //break-point?
		}
		return chr($code);
	}
	
	public function encode() {
		
		for ($round = 0; $round < $this -> iterations; $round++) {
			echo "Iteration: " . $round . "<br>";
			if ($round == 1) {
				echo "Non-default iterations set, changing strings... <br>"; //Debug
				$this -> str = $this -> encoded_str;
			}
			for ($i = 0, $j = strlen($this->str); $i < $j; $i++) {
				$params = $this -> keyword[($i % strlen($this -> keyword))] + strlen($this -> str); //add randomness with dependencies of user-input
				if (($i != 0) && ($i != strlen($this -> str) - 1)) { //here we check for first and last char in string
					// E[i] = A[i-1] + A[i] + A[i+1]
					$this -> encoded_str[$i] = $this -> codeToChar(32 + ($params + $this -> charToCode($this -> str[$i - 1]) + $this -> charToCode($this -> str[$i]) + $this -> charToCode($this -> str[$i + 1])) % 95); 
				} elseif ($i ==0) {	//check if this is first char
					// E[0] = A[last] + A[0] + A[1]
					$this -> encoded_str[$i] = $this -> codeToChar(32 + ($params + $this -> charToCode($this -> str[$i]) + $this -> charToCode($this -> str[$i + 1])) % 95);
					//$this -> encoded_str[$i] = $this -> codeToChar(32 + ($params + $this -> charToCode($this -> str[strlen($this -> str) - 1]) 	+ $this -> charToCode($this -> str[$i]) + $this -> charToCode($this -> str[$i + 1])) % 95); 
				} else { 			//else this is last char
					// E[last] = A[last-1] + A[last] + A[0]
					$this -> encoded_str[$i] = $this -> codeToChar(32 + ($params + $this -> charToCode($this -> str[$i - 1]) + $this -> charToCode($this -> str[$i])) % 95);
					//$this -> encoded_str[$i] = $this -> codeToChar(32 + ($params + $this -> charToCode($this -> str[$i - 1]) + $this -> charToCode($this -> str[$i]) + $this -> charToCode($this -> str[0]))% 95);
				}
			}
		}
	}
}
  	if(!empty($_POST['str'])){ // Did the user entered data?

		$str = $_POST['str'];
		$iterations = 1;
		
		if(!empty($_POST['iterations'])){ //checking user-input
			if ($iterations > 0) {
				$iterations = intval($_POST['iterations']);
			}
			else {
				$iterations = 1;
			}
		}
		
		if(!empty($_POST['key'])){ // Does user provide us key?
			$keyword = $_POST['key'];
			echo "Provided input string \"". $str . "\" and key is " . $keyword . "<br>";
			//echo "Creating with key...<br>"; //Debug
		  	$UserString = new encode($str, $iterations, $keyword);
		  	//echo "Object created.<br>"; //Debug
	  	}
		else {
			echo "Provided input string \"". $str . "\" with default key<br>";
			//echo "Creating without key...<br>"; //Debug
			$UserString = new encode($str, $iterations);
		}
		$UserString -> encode(); //we can do it in creating function, but we need to pass a parameter "iterations" in __construct()
		
		echo "<p>Result:<br>";
		echo $UserString -> returnString();
  	}
?>
</p>
</body>
</html>

