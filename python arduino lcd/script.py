from SwSpotify import spotify
import serial
_serialPort = serial.Serial('COM6',9600)
previously_played = ''
while True:
    currently_playing = spotify.current()
    if currently_playing[0] != previously_played:
        _serialPort.write(" from ".join(spotify.current()).encode())
        previously_played = currently_playing[0]