#lang racket

(provide conway-create conway-evolve conway-toggle conway-rows conway-cols conway-create-random)

(define (iteration n f-each f-take l)
  (define (iteration-rec i l l2)
      (if (= i n)
          (reverse l2)
          (iteration-rec (+ i 1)
                         (f-take l)
                         (cons (f-each i l) l2)))
  )
  (iteration-rec 0 l empty)
)

(define (sum l)
  (apply + l)
)

(define (map-3 f)
  (λ (x) (map f (take x 3)))
)

(define (xevolve-cell i xboard)
  (define cell-value
    (second (second xboard)))
  (define population
    ((compose1 sum (map-3 sum) (map-3 (map-3 identity))) xboard))
  (define neighbors
    (- population cell-value))
  (cond [(= 2 neighbors) cell-value]
        [(= 3 neighbors) 1]
        [else 0])
)

(define (xevolve xboard rows cols)
  (define (xevolve-row i xboard)
    (iteration cols xevolve-cell (map-3 rest) xboard)
  )
  (iteration rows xevolve-row rest xboard)
)

(define (extend board cols)
  (define (pad l) (append '(0) l '(0)))
  (define zeros (make-list (+ 2 cols) 0))  
  (append (list zeros) (map pad board) (list zeros))
)


(define (conway-create-random rows cols)
  (build-list rows
              (λ (x) (build-list cols (λ (x) (random 2)))))
)

(define (conway-create rows cols)
  (build-list rows
              (λ (x) (make-list cols 0)))
)

(define (conway-rows board)
  (length board)
)

(define (conway-cols board)
  (if (pair? board) (length (first board)) 0)
)

(define (conway-evolve board)
  (let ([rows (conway-rows board)]
        [cols (conway-cols board)])
       (xevolve (extend board cols) rows cols))
)

(define (conway-for-each f board)
  (define rows (conway-rows board))
  (define cols (conway-cols board))
  (define (for-each-row r row)
    (define (for-each-col c col)
      (f r c (first col))
    )
    (iteration cols for-each-col rest (first row))
  )
  (iteration rows for-each-row rest board)
)

(define (conway-toggle board row col)
  (define (toggle r c v)
    (if (and (= r row) (= c col)) (- 1 v) v)
  )
  (conway-for-each toggle board)
)