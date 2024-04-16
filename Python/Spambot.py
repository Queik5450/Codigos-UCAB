# Este script envía un mensaje varias veces a un grupo de Telegram
import telegram
import asyncio

# Token de acceso al bot de Telegram (Nuestro querido Spambot llamado Queikbot)
TOKEN = str(input("Ingrese el token del bot creado: "))

async def send_messages():
    # ID del grupo de Telegram
    GROUP_ID = str(input("Ingrese la ID del grupo que quiere fastidiar, recuerde incluir el negativo: "))
    # Mensaje a enviar
    mensaje = str(input("Ingrese mensaje a enviar: "))
    # Número de veces que se enviará el mensaje
    num_veces = int(input("Ingrese el número de veces que quiere enviar el mensaje: "))
    #Pausa entre mensajes
    pausa = int(input("Ingrese el tiempo de pausa entre mensajes (en segundos): "))
    # Crear una instancia del bot de Telegram
    bot = telegram.Bot(token=TOKEN)
    # Enviar el mensaje varias veces al grupo
    for _ in range(num_veces):
        await bot.send_message(chat_id=GROUP_ID, text=mensaje)
        await asyncio.sleep(pausa)
# Ejecuta la función send_messages en un bucle de eventos
asyncio.run(send_messages())