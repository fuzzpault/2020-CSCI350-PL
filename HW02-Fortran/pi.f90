program pi

   ! This program estimates pi
   implicit none  ! Disables the auto type ijk....

   ! Type declarations
   real :: x,y,dist
   integer :: i, in_count, total
   
   total = 100000000

   ! Executable statements
   in_count = 0
   i = total
   do while (i > 0)
      x = RAND(0) - 0.5
      y = RAND(0) - 0.5
      dist = sqrt(x * x + y * y)
      if (dist < 0.5) then
         in_count = in_count + 1
      end if
      i = i - 1
   end do
   print *, "in: ", in_count, 'total', total
   print *, "pi: ", REAL(in_count) * 4.0 / total
end program pi