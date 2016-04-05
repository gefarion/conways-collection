#lang racket

(require 2htdp/image)
(require "conway-it.rkt")

(provide conway-draw SQUARE_SIZE)

(define SQUARE_SIZE 30)
(define SQUARE_OUTLINE "black")
(define CIRCLE_SIZE 12)
(define CIRCLE_COLOR "navy")

(define SQUARE
  (square SQUARE_SIZE "outline" SQUARE_OUTLINE)
)

(define CIRCLE
  (circle CIRCLE_SIZE "solid" CIRCLE_COLOR)
)

(define conway-draw-live-cell
  (overlay SQUARE CIRCLE)
)

(define conway-draw-dead-cell SQUARE)

(define (conway-draw-cell v)
  (if (zero? v)
      conway-draw-dead-cell
      conway-draw-live-cell)
)

(define (conway-draw-row row)
  (if (list? row)
      (apply beside (map conway-draw-cell row))
      (apply beside (vector->list (vector-map conway-draw-cell row))))
)

(define (conway-draw board)
  (if (list? board)
      (apply above (map conway-draw-row board))
      (apply above (vector->list (vector-map conway-draw-row board))))
)