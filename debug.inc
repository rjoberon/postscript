/log-stack {              % fname
    (\n### ) print
    print
    ( ###\n) print
    print-stack
    %pstack
} def

/print-stack {           % STACK
    count 1 add 2        % STACK cnt+1 2
    {
        dup              % STACK cnt+1 2 2
        2 index          % STACK cnt+1 2 2 cnt+1
        gt               % STACK cnt+1 2 2 > cnt+1
        {                % STACK cnt+1 2
            exit
        } if             % STACK cnt+1 2
        dup              % STACK cnt+1 2 2
        index            % STACK cnt+1 2 item
        ppitem           % STACK cnt+1 2
        1 add            % STACK cnt+1 3
    } loop               % STACK cnt+1 cnt+1
    pop pop              % STACK
} def

/ppitem {                % item
%    (| ) print
    dup type exec
    (\n) print
} def

/nametype    { (/) print (         ) cvs print } def
/marktype    { (-mark-) print pop } def
/nulltype    { (null) print pop } def
/integertype { (    ) cvs print } def
/booleantype { (     ) cvs print } def
/realtype    { (       ) cvs print } def
/arraytype {             % arr
    1 dict begin
    /arraytype {
        ([) print
        print-arraylen
        (...]) print
    } def
    ([) print
    {dup type exec ( ) print} forall
    (]) print
    end
} def

/print-arraylen {        % arr
    length dup           % len len
    0 ne                 % len len!=0
    {                    % len
        (    ) cvs print %
        (: ) print
    } {                  % len
        pop              %
    } ifelse
} def
