using System.IO;
using System.Threading.Tasks;
using UnityEngine;
using System;

/// <summary>
/// The lightweight data structure to be saved.
/// </summary>
[Serializable]
public struct GameSaveData
{
    public int PlayerLevel;
    public float CurrentHealth;
    public Vector3 LastCheckpoint;
}

/// <summary>
/// A non-blocking, asynchronous Save/Load Manager.
/// </summary>
public static class SaveLoadManager
{
    private static readonly string SavePath = Application.persistentDataPath + "/save_01.json";

    /// <summary>
    /// Writes data to disk on a background thread. 0ms impact on main thread.
    /// </summary>
    public static async Task SaveGameAsync(GameSaveData dataToSave)
    {
        try
        {
            // Convert to JSON (Running on main thread, but fast for structs)
            string jsonString = JsonUtility.ToJson(dataToSave);

            // Push the actual hard-drive write operation to a background CPU core
            await Task.Run(async () => 
            {
                using (StreamWriter writer = new StreamWriter(SavePath))
                {
                    await writer.WriteAsync(jsonString);
                }
            });

            Debug.Log($"[SaveLoadManager] Game saved asynchronously to {SavePath}");
        }
        catch (Exception e)
        {
            Debug.LogError($"[SaveLoadManager] Failed to save game: {e.Message}");
        }
    }

    /// <summary>
    /// Reads data from disk on a background thread.
    /// </summary>
    public static async Task<GameSaveData?> LoadGameAsync()
    {
        if (!File.Exists(SavePath))
        {
            Debug.LogWarning("[SaveLoadManager] No save file found.");
            return null;
        }

        try
        {
            string jsonString = "";

            // Read from hard-drive on a background core
            await Task.Run(async () =>
            {
                using (StreamReader reader = new StreamReader(SavePath))
                {
                    jsonString = await reader.ReadToEndAsync();
                }
            });

            // Deserialize back into struct
            return JsonUtility.FromJson<GameSaveData>(jsonString);
        }
        catch (Exception e)
        {
            Debug.LogError($"[SaveLoadManager] Failed to load game: {e.Message}");
            return null;
        }
    }
}