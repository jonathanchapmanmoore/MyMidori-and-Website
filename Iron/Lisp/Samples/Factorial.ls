;; Factorial
(def fact(n) 
	(if (is n 0) 1 (* n (fact (- n 1)))))

(fact 5)