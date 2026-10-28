# Resumen de Queues en System Verilog 

Hay de 2 tipos: **bounded** y **unbounded**

## Bounded 

Tiene un numero limitado de entries o tiene un tamaño especifico 

## Unbounded 

Tiene entries ilimitadas y el tamaño no ha sido especificado 

# Como declarar queues 

```
data_type queue_nombre[$]; 
```

## Ejemplo de declaracion 
```
bit queue_1[$]; //es una unbounded de bits llamada 1

byte queue_hola[$:2]; //es bounded de bits con 3 entries y se llama hola
```

## Ejemplo de inicializacion 
```
queue_1 = {0,1,2,3};

queue_hola = {1,2,3};
```

# Metodos de queue 
`
size()
`

`
insert()
`

`
delete()
`

`
push_front()
`

`
push_back()
`

`
pop_front()
`

`
pop_back()
`
