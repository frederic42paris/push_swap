SRCS = check_error.o \
create_array.o \
display.o \
instructions_a.o \
instructions_b.o \
main.o \
sort_three.o \
sort_five.o \
sort_large.o \
sort_large_utils.o \
sort_large_lib.o \
utils.o \

NAME = push_swap

ARG1="9 8 7 6 5 one"
ARG2="9 8 7 6 5 5"
ARG3="9 8 7 6 5 2147483648"
ARG4=""

ARG5="42"
ARG6="2 3"
ARG7="0 1 2 3"
ARG8="0 1 2 3 4 5 6 7 8 9"

ARG9="2 1 0"
ARG10="3 2 1"

ARG11="1 5 2 4 3"
ARG12="5 4 3 1 2"

ARG13="22 61 37 94 33 76 11 67 90 36 14 3 98 12 47 23 70 53 20 44 46 19 30 35 97 43 27 91 96 52 93 31 89 74 54 79 10 48 49 73 50 15 92 87 38 64 68 81 99 57 40 72 71 29 41 88 56 63 95 9 32 62 59 60 65 45 18 86 7 42 21 5 1 8 85 4 16 51 55 24 78 39 75 66 84 25 100 26 13 80 2 82 69 17 58 34 6 83 28 77"
ARG14="221 325 159 42 361 390 36 18 12 423 350 111 498 275 74 120 422 443 87 195 139 289 27 82 256 412 414 394 331 56 29 63 244 54 198 178 257 124 458 122 459 272 267 10 297 162 58 322 28 319 199 163 370 404 254 160 288 143 152 417 240 482 72 211 352 341 65 305 168 46 210 258 186 444 465 9 230 425 317 376 126 474 252 239 401 196 318 287 145 347 487 475 353 291 208 379 309 216 488 457 476 136 300 73 191 217 328 329 99 262 177 190 271 226 96 193 135 110 3 107 219 77 204 53 170 86 418 432 105 133 274 169 2 150 84 19 255 479 148 80 486 463 214 410 346 265 144 146 125 237 182 207 369 362 363 104 93 471 273 500 43 497 23 118 35 121 59 138 201 278 455 340 470 469 308 448 6 396 1 103 332 85 38 165 466 327 270 478 315 304 435 113 90 441 229 222 467 180 306 30 60 492 462 261 336 314 155 453 5 382 310 377 330 11 25 495 323 276 293 282 409 248 316 374 268 393 449 69 175 493 452 301 312 335 424 427 290 250 342 406 17 223 358 480 385 233 473 481 57 4 16 447 129 48 388 102 51 436 245 421 75 450 176 454 106 173 430 13 127 98 236 313 419 83 485 294 380 307 489 14 348 397 41 78 337 203 251 283 153 185 375 212 151 284 351 364 405 194 161 174 243 79 76 384 366 461 117 387 381 428 407 52 429 71 26 286 451 116 142 490 181 360 303 67 130 62 338 55 40 154 259 302 134 128 279 189 372 460 296 184 149 47 456 333 354 371 403 132 89 266 20 334 299 215 326 411 119 445 95 446 33 320 249 472 179 413 281 365 172 101 415 21 357 402 269 7 355 49 386 197 442 123 280 260 147 158 373 408 91 263 426 37 494 140 15 496 298 311 68 383 206 32 389 209 50 202 484 295 344 112 137 395 166 231 141 324 114 367 156 61 438 345 108 434 368 356 253 431 439 81 238 131 92 420 285 499 400 213 416 392 22 247 399 225 437 115 45 171 167 31 164 292 34 241 321 66 391 227 343 70 24 483 378 224 192 235 64 242 183 220 228 205 398 39 349 359 477 246 491 44 234 339 100 464 232 218 468 440 277 187 157 200 88 8 97 433 109 264 94 188"

all: $(NAME)

$(NAME): $(SRCS)
	make -C ./lib_ft
	make -C ./printf
	cc -Wall -Wextra -Werror -o $(NAME) $(SRCS) ./printf/libftprintf.a ./lib_ft/libft.a

%.o:%.c 
	cc -Wall -Wextra -Werror -o $@ -c $<

clean:
	make clean -C ./lib_ft
	make clean -C ./printf
	rm -f $(SRCS)

fclean: clean
	make fclean -C ./lib_ft
	make fclean -C ./printf
	rm -f $(NAME)

re: fclean all

tester:
	printf "\n>> error\n"
	./push_swap $(ARG1)
	./push_swap $(ARG2)
	./push_swap $(ARG3)
	./push_swap $(ARG4)

	./push_swap 9 8 7 6 5 one
	./push_swap 9 8 7 6 5 5
	./push_swap 9 8 7 6 5 2147483648
	./push_swap 

	printf "\n>> sorted\n"
	./push_swap $(ARG5)
	./push_swap $(ARG5) | ./checker_linux $(ARG5)
	./push_swap $(ARG6)
	./push_swap $(ARG6) | ./checker_linux $(ARG6)
	./push_swap $(ARG7)
	./push_swap $(ARG7) | ./checker_linux $(ARG7)
	./push_swap $(ARG8)
	./push_swap $(ARG8) | ./checker_linux $(ARG8)

	./push_swap 42
	./push_swap 2 3
	./push_swap 0 1 2 3
	./push_swap 0 1 2 3 4 5 6 7 8 9

	printf "\n>> 3 values\n"
	./push_swap $(ARG9) | wc -l
	./push_swap $(ARG9) | ./checker_linux $(ARG9)
	./push_swap $(ARG10) | wc -l
	./push_swap $(ARG10) | ./checker_linux $(ARG10)

	printf "\n>> 5 values\n"
	./push_swap $(ARG11) | wc -l
	./push_swap $(ARG11) | ./checker_linux $(ARG11)
	./push_swap $(ARG12) | wc -l
	./push_swap $(ARG12) | ./checker_linux $(ARG12)

	printf "\n>> 100 values\n"
	./push_swap $(ARG13) | wc -l
	./push_swap $(ARG13) | ./checker_linux $(ARG13)
	printf "\n>> 500 values\n"
	./push_swap $(ARG14) | wc -l
	./push_swap $(ARG14) | ./checker_linux $(ARG14)

	valgrind --leak-check=full ./push_swap $(ARG1)

.PHONY: all clean fclean re
